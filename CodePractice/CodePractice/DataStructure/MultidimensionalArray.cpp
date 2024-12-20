#include "MultidimensionalArray.h"

#include <iostream>
#include <array>
#include <list>
#include <vector>
using namespace std;

void MultidimensionalArray::Execute()
{
    //Normal Array
    // 2D array of fixed size (3x3)
    int normalArray[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Accessing elements
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << normalArray[i][j] << " ";
        }
        cout << endl;
    }
    
    // Dynamic Array
    // Creating a 2D dynamic array
    int rows = 3, cols = 3;
    int** dynamicArray = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[cols];
    }

    // Initializing and accessing elements
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dynamicArray[i][j] = value++;
            cout << dynamicArray[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating memory
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;

    //Standard Array
    //std::array for 2D array (3x3)
    array<array<int, 3>, 3> standardArray = {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};

    // Accessing elements
    for (const auto& row : standardArray) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    //Standard Vector
    // std::vector for 2D array
    vector<vector<int>> vectorArray = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Accessing elements
    for (const auto& row : vectorArray) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    std::list<int> test;
}
