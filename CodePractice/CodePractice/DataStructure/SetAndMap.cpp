#include "SetAndMap.h"

#include <iostream>
#include <set>
#include <map>
using namespace std;

void SetAndMap::Execute()
{
    // Use for looking up data quickly, cannot have duplicated value. Both are sorted which mean a lookup order of O(NLog(N))
    // Unordered map and set would have a look up value of O(1), but conflicting hashset might make it to O(N)
    // Set = automatic sorting when an element is inserted or deleted, allowing binary search, though you use the Find to get a value
    // Map = link pair where a non sequencial key is used to find a specific value 
    
    // Set
    // Create a set
    set<int> mySet;

    // Insert elements
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(15);

    // Attempting to insert a duplicate element (ignored in set)
    mySet.insert(10);

    // Print the set
    cout << "Set elements (sorted): ";
    for (const auto& item : mySet) {
        cout << item << " ";
    }
    cout << endl;

    // Check if an element exists
    if (mySet.find(15) != mySet.end()) {
        cout << "15 is in the set." << endl;
    } else {
        cout << "15 is not in the set." << endl;
    }

    // Erase an element
    mySet.erase(10);
    cout << "After erasing 10: ";
    for (const auto& item : mySet) {
        cout << item << " ";
    }
    cout << endl;

    // Size of the set
    cout << "Set size: " << mySet.size() << endl;

    //Map
    map<string, int> myMap;

    myMap["Alice"] = 30;
    myMap["Bob"] = 25;
    myMap["Charlie"] = 35;

    cout << "Alice's age: " << myMap["Alice"] << endl;

    cout << "Map elements (sorted by keys):" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    if (myMap.find("Bob") != myMap.end()) {
        cout << "Bob is in the map." << endl;
    } else {
        cout << "Bob is not in the map." << endl;
    }

    myMap.erase("Alice");
    cout << "After erasing Alice:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Map size: " << myMap.size() << endl;
}
