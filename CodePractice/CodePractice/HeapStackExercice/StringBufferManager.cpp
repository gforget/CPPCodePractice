#include "StringBufferManager.h"

#include <cstring>

StringBufferManager::StringBufferManager(int capacity)
{
    // These arrays are allocated on the heap
    StringBufferCapacity = capacity;
    AllStrings = new char*[capacity];
    IsStoredOnHeap = new bool[capacity];
    
    // Track heap allocation
    HeapAllocatedBytes = capacity * (sizeof(char*) + sizeof(bool));
    
    // Track stack allocation (includes member variables and the stack buffer)
    StackAllocatedBytes = sizeof(StringBufferManager) - sizeof(char**) - sizeof(bool*);
}

StringBufferManager::~StringBufferManager()
{
    // Free each heap-allocated string
    for (int i = 0; i < CurrentSize; i++) {
        if (IsStoredOnHeap[i]) {
            delete[] AllStrings[i];
        }
    }
    
    // Free the arrays of pointers and flags
    delete[] AllStrings;
    delete[] IsStoredOnHeap;
}

bool StringBufferManager::addString(const char* str)
{
    if (CurrentSize >= StringBufferCapacity) {
        return false;
    }
    
    size_t length = strlen(str);
    
    // STACK ALLOCATION: If string is small enough and we have stack space
    if (length < SMALL_STRING_MAX - 1 && StackBufferUsed < SMALL_STRING_MAX) {
        // Copy into our stack buffer
        char* destBuffer = StackBuffer[StackBufferUsed];
        strcpy_s(destBuffer, SMALL_STRING_MAX, str);
        
        // Point to stack-allocated buffer
        AllStrings[CurrentSize] = destBuffer;
        IsStoredOnHeap[CurrentSize] = false;
        
        // Update stats
        StackAllocatedBytes += length + 1;
        StackBufferUsed++;
    }
    // HEAP ALLOCATION: For larger strings or when stack buffer is full
    else {
        // Allocate memory on the heap
        char* heapStr = new char[length + 1];
        strcpy_s(heapStr, length + 1, str);
        
        // Store pointer
        AllStrings[CurrentSize] = heapStr;
        IsStoredOnHeap[CurrentSize] = true;
        
        // Update stats
        HeapAllocatedBytes += length + 1;
    }
    
    CurrentSize++;
    return true;
}

char* StringBufferManager::concatenate(const char* separator)
{
    // Calculate total length needed
    size_t totalLength = 0;
    size_t sepLength = strlen(separator);
    
    for (int i = 0; i < CurrentSize; i++) {
        totalLength += strlen(AllStrings[i]);
        if (i < CurrentSize - 1) {
            totalLength += sepLength;
        }
    }
    
    // HEAP ALLOCATION: Result is always on heap - could be large
    char* result = new char[totalLength + 1]; // +1 for null terminator
    HeapAllocatedBytes += totalLength + 1;     // Track allocation
    
    // Create the concatenated string
    result[0] = '\0';
    for (int i = 0; i < CurrentSize; i++) {
        strcat_s(result, totalLength + 1, AllStrings[i]);
        if (i < CurrentSize - 1) {
            strcat_s(result, totalLength + 1, separator);
        }
    }
    
    return result;
}

size_t StringBufferManager::getHeapAllocatedBytes() const
{
    return HeapAllocatedBytes;
}

size_t StringBufferManager::getStackAllocatedBytes() const
{
    return StackAllocatedBytes;
}

void StringBufferManager::getStorageStats(int& onStack, int& onHeap) const
{
    onStack = 0;
    onHeap = 0;
    
    for (int i = 0; i < CurrentSize; i++) {
        if (IsStoredOnHeap[i]) {
            onHeap++;
        } else {
            onStack++;
        }
    }
}
