#pragma once
#include <iostream>

template<typename T>
class Container {
    
private:
    T* elements;
    size_t size;
    size_t capacity;

public:
    // Constructor, destructor, copy constructor, assignment operator
    Container();
    ~Container();
    Container(const Container& other);
    Container& operator=(const Container& other);
    
    // Core functionality
    void add(const T& element);
    T& get(size_t index);
    const T& get(size_t index) const;
    size_t getSize() const;
    
    // Print all elements
    void print() const;
};

template <typename T>
Container<T>::Container()
{
    capacity = 10;
    size = 0;
    elements = new T[capacity];
}

template <typename T>
Container<T>::~Container()
{
    delete[] elements;
}

template <typename T>
Container<T>::Container(const Container& other)
{
    size = other.size;
    capacity = other.capacity;
    elements = new T[capacity];
    
    for (size_t i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
Container<T>& Container<T>::operator=(const Container& other)
{
    if (this != &other) {
        delete[] elements;
        
        size = other.size;
        capacity = other.capacity;
        elements = new T[capacity];
        
        for (size_t i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
void Container<T>::add(const T& element)
{
    if (size >= capacity) {
        size_t newCapacity = capacity * 2;
        T* newElements = new T[newCapacity];
        
        for (size_t i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
    
    elements[size] = element;
    size++;
}

template <typename T>
T& Container<T>::get(size_t index)
{
    return elements[index];
}

template <typename T>
const T& Container<T>::get(size_t index) const
{
    return elements[index];
}

template <typename T>
size_t Container<T>::getSize() const
{
    return size;
}

template <typename T>
void Container<T>::print() const
{
    for (int i=0; i<size;i++)
    {
        std::cout << elements[i] << std::endl;
    }
}
