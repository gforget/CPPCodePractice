#include "SimpleArray.h"

#include <iostream>
#include <array>
#include <vector>

void SimpleArray::Execute()
{
    //Normal Array on stack, size is fixed at compilation and cannot change
    int MyArray[] = {1,2,3,4,5};
    size_t  length = sizeof(MyArray) / sizeof(MyArray[0]); //only way to detect size, though the size is fixed, might as well just write it

    //Dynamic Array, size can be change at runtime, on the heap
    int* MyArray2 = new int[5];
    size_t  length2 = 5; // Store the length manually, only way to do
    delete[] MyArray2; // Clean up memory

    //Standard Array - can resize at runtime, know the size dynamically, but can't push element easely. Elements on the stack when use properly
    std::array<int, 5> MyArray3 = {1, 2, 3, 4, 5};
    size_t  length3 = MyArray3.size();

    //Standard Vector - can add element at runtime. Elements always on the heap, the vector itself and it metadata can be on the stack.
    std::vector<int> MyVector = {1, 2, 3, 4, 5};
    size_t  length4 = MyVector.size();
    MyVector.push_back(6); // added 6 to the elements
}
