#pragma once
#include <cstddef>

class StringBufferManager {
public:
    // Constructor - Initialize with capacity (max number of strings)
    StringBufferManager(int capacity);
    
    // Destructor - Clean up all allocated memory
    ~StringBufferManager();
    
    // Prevent accidental copies (rule of three)
    StringBufferManager(const StringBufferManager&) = delete;
    StringBufferManager& operator=(const StringBufferManager&) = delete;
    
    // Add a new string to the collection (returns false if full)
    bool addString(const char* str);
    
    // Concatenate all strings with the given separator and return result
    char* concatenate(const char* separator);
    
    // Return total bytes allocated on heap by this manager
    size_t getHeapAllocatedBytes() const;
    
    // Return total bytes used on stack by this manager
    size_t getStackAllocatedBytes() const;
    
    // Return number of strings stored on stack vs heap
    void getStorageStats(int& onStack, int& onHeap) const;
    
private:
    // Constants
    static const int SMALL_STRING_MAX = 16;  // Max length for stack storage
    
    // Stack-allocated storage for small strings
    char** AllStrings;             // Array of pointers to all strings
    bool* IsStoredOnHeap;          // Tracks which strings are on heap vs stack
    
    // Stack buffer for small strings (Fixed size, stack-allocated)
    char StackBuffer[SMALL_STRING_MAX][SMALL_STRING_MAX];
    int StackBufferUsed = 0;       // Number of slots used in stack buffer
    
    // Stats
    int StringBufferCapacity;      // Max number of strings we can store
    int CurrentSize = 0;           // Current number of strings stored
    size_t HeapAllocatedBytes = 0; // Bytes allocated on heap
    size_t StackAllocatedBytes = 0;// Bytes used from stack
};
