#include "Sorting.h"

#include <iostream>
#include <vector>
#include <algorithm>

void Sorting::printVector(const std::vector<std::pair<int, char>>& vec)
{
    for (const auto& item : vec)
    {
        std::cout << "(" << item.first << ", " << item.second  << ") ";
    }
    
    std::cout << '\n';
}

void Sorting::Execute()
{
    // Example vector with duplicate keys to show stability
    std::vector<std::pair<int, char>> data = {{3, 'A'}, {1, 'B'}, {3, 'C'}, {2, 'D'}, {1, 'E'}, {3, 'F'}};

    std::cout << "Original data:\n";
    printVector(data);

    // Ascending order with std::sort
    std::vector<std::pair<int, char>> sortAsc = data;
    std::sort(sortAsc.begin(), sortAsc.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    std::cout << "\nSorted (ascending) using std::sort:\n";
    printVector(sortAsc);

    // Descending order with std::sort
    std::vector<std::pair<int, char>> sortDesc = data;
    std::sort(sortDesc.begin(), sortDesc.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    std::cout << "\nSorted (descending) using std::sort:\n";
    printVector(sortDesc);

    // Ascending order with std::stable_sort
    std::vector<std::pair<int, char>> stableSortAsc = data;
    std::stable_sort(stableSortAsc.begin(), stableSortAsc.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    std::cout << "\nSorted (ascending) using std::stable_sort:\n";
    printVector(stableSortAsc);

    // Descending order with std::stable_sort
    std::vector<std::pair<int, char>> stableSortDesc = data;
    std::stable_sort(stableSortDesc.begin(), stableSortDesc.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    std::cout << "\nSorted (descending) using std::stable_sort:\n";
    printVector(stableSortDesc);
}
