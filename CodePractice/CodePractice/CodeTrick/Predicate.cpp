#include "Predicate.h"
#include <iostream>

bool Predicate::IsEven(int x)
{
    return x%2 == 0;
}

std::vector<int> Predicate::AllEven(const std::vector<int>& vec, std::function<bool(int)> pred)
{
    std::vector<int> result;

    for (int i=0; i<vec.size(); i++)
    {
        if (pred(vec[i]))
        {
            result.push_back(vec[i]);
        }
    }

    return result;
}

void Predicate::Execute()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    
    // how you create a predicate with a member function
    std::function<bool(int)> pred = std::bind(&Predicate::IsEven, this, std::placeholders::_1); 
    std::vector<int> AllEvenVector = AllEven(numbers, pred);

    for (int i=0; i<AllEvenVector.size(); i++)
    {
        std::cout << "Number of even numbers: " << AllEvenVector[i] << std::endl;    
    }
}