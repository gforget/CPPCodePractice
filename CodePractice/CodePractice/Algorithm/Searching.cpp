#include "Searching.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

void Searching::Execute()
{
    //With normal arrays
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // The array must be sorted for binary_search to work
    std::sort(arr, arr + size);

    int value = 5;
    if (std::binary_search(arr, arr + size, value)) {
        std::cout << value << " found in array.\n";
    } else {
        std::cout << value << " not found in array.\n";
    }
    
    // With Vector
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // Using std::find
    int target1 = 30;
    auto it = std::find(numbers.begin(), numbers.end(), target1);

    if (it != numbers.end()) {
        std::cout << "Found " << target1 << " at index " << std::distance(numbers.begin(), it) << '\n';
    } else {
        std::cout << target1 << " not found\n";
    }

    // Using std::binary_search
    // Note: std::binary_search requires the container to be sorted
    int target2 = 40;
    if (std::binary_search(numbers.begin(), numbers.end(), target2)) {
        std::cout << target2 << " exists in the list\n";
    } else {
        std::cout << target2 << " does not exist in the list\n";
    }

    // Demonstrating binary_search with an absent value
    int target3 = 35;
    if (std::binary_search(numbers.begin(), numbers.end(), target3)) {
        std::cout << target3 << " exists in the list\n";
    } else {
        std::cout << target3 << " does not exist in the list\n";
    }

    //Iterator can be moved, but depend on the data structure.
    
    //For random access DS like Array and Vector, you increment it.
    std::vector<int>::iterator it2 = numbers.begin() + 2;

    //For non-random access DS like a List or a Set, you use the advance function
    std::list<int> numbers2 = {10, 20, 30, 40, 50};
    std::list<int>::iterator it3 = numbers2.begin();
    std::advance(it3, 2);
}
