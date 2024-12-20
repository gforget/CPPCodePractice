#include "DoubleLinkedListAndDoubleEndedQueue.h"

#include <iostream>
#include <list>
#include <deque>
using namespace std;

void DoubleLinkedListAndDoubleEndedQueue::Execute()
{
    //Use for frequent insertion and deletions
    //Double link = insertion and deletion anywhere, random access slow
    //Double Ended Queue = fast insertion at the ends, random access fast
    
    //Double Linked List
    // Create a list
    list<int> myList;

    // Add elements to the list
    myList.push_back(10); // Add at the back
    myList.push_back(20);
    myList.push_front(5); // Add at the front

    // Print the list
    cout << "List: ";
    for (const auto& item : myList) {
        cout << item << " ";
    }
    cout << endl;

    // Remove elements
    myList.pop_front(); // Remove from the front
    cout << "After pop_front: ";
    for (const auto& item : myList) {
        cout << item << " ";
    }
    cout << endl;

    myList.pop_back(); // Remove from the back
    cout << "After pop_back: ";
    for (const auto& item : myList) {
        cout << item << " ";
    }
    cout << endl;

    // Insert at a specific position
    auto it = myList.begin();
    myList.insert(it, 15); // Insert 15 at the beginning
    cout << "After inserting 15 at the beginning: ";
    for (const auto& item : myList) {
        cout << item << " ";
    }
    cout << endl;

    //DoubleEndedQueue
    // Create a deque
    deque<int> myDeque;

    // Add elements to the deque
    myDeque.push_back(10);  // Add at the back
    myDeque.push_back(20);
    myDeque.push_front(5);  // Add at the front

    // Print the deque
    cout << "Deque: ";
    for (const auto& item : myDeque) {
        cout << item << " ";
    }
    cout << endl;

    // Remove elements
    myDeque.pop_front(); // Remove from the front
    cout << "After pop_front: ";
    for (const auto& item : myDeque) {
        cout << item << " ";
    }
    cout << endl;

    myDeque.pop_back(); // Remove from the back
    cout << "After pop_back: ";
    for (const auto& item : myDeque) {
        cout << item << " ";
    }
    cout << endl;

    // Access elements
    cout << "Front element: " << myDeque.front() << endl;
    cout << "Back element: " << myDeque.back() << endl;
}
