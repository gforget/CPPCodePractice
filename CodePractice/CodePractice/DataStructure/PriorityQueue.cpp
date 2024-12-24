#include "PriorityQueue.h"

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

void PriorityQueue::Execute()
{
    //Min Heap
    // Define the lambda for the Min Heap comparison
    std::function<bool(int, int)> minHeapComparator = [](int a, int b) {
        return a > b;  // Reverse the comparison for Min Heap
    };

    // Create the Min Heap using the lambda
    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> minHeap(minHeapComparator);

    // Inserting elements into the Min Heap
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(30);
    minHeap.push(15);

    std::cout << "Min Heap (Extracting elements):\n";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << "\n";
    
    //Max heap
    std::priority_queue<int> maxHeap;

    // Inserting elements into the Max Heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(30);
    maxHeap.push(15);

    std::cout << "Max Heap (Extracting elements):\n";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    
}
