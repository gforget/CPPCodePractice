#include <iostream>
#include "TestStringBufferManager.h"
#include "StringBufferManager.h"

void TestStringBufferManager::Execute()
{
    // StringBufferManager object itself is on the stack
    StringBufferManager manager(10);
    
    // Add various strings - some small, some large
    manager.addString("Hi");                 // Small - should go on stack
    manager.addString("Hello");              // Small - should go on stack
    manager.addString("This is a longer string that won't fit in stack buffer"); // Large - heap
    manager.addString("Another small one");  // Large - heap
    
    // Get statistics
    int onStack, onHeap;
    manager.getStorageStats(onStack, onHeap);
    
    std::cout << "Strings stored on stack: " << onStack << std::endl;
    std::cout << "Strings stored on heap: " << onHeap << std::endl;
    std::cout << "Stack bytes used: " << manager.getStackAllocatedBytes() << std::endl;
    std::cout << "Heap bytes used: " << manager.getHeapAllocatedBytes() << std::endl;
    
    // Concatenate strings
    char* result = manager.concatenate(" | ");
    std::cout << "Result: " << result << std::endl;
    
    // Don't forget to free the result (it's on the heap)
    delete[] result;
}
