#include "RemoveSpecificArray.h"
#include <iostream>
#include <cmath>
#include <limits>

std::vector<std::pair<int, int>> RemoveSpecificArray::select_subarray(const std::vector<int>& arr)
{
    //std::cout << arr << std::endl;
    std::vector<std::pair<int, int>> Answer;
    
    long long LowestQ = std::numeric_limits<long long>::max();
    
    int SkippedIndex = 0;
    
    for (int i=0; i<arr.size(); i++)
    {
        long long SubSum = 0.0f;
        long long SubProduct = 1.0f;
        
        for (int j=0; j<arr.size(); j++)
        {
            if (j == SkippedIndex) continue;
            SubSum += arr[j];
            SubProduct *= arr[j];
        }

        if (SubSum != 0.0f)
        {
            float q = std::abs(static_cast<long long>(SubProduct/SubSum));
            if (q == LowestQ)
            {
                Answer.push_back({i, arr[i]});
            }
            else if (q < LowestQ)
            {
                LowestQ = q;
                Answer.clear();
                Answer.push_back({i, arr[i]});
            }
        }
        
        SkippedIndex++;
    }
    
    return Answer;
}

void RemoveSpecificArray::Execute()
{
    //https://www.codewars.com/kata/581bb3c1c221fb8e790001ef/train/cpp
    //auto test = select_subarray({1,23,2,-8,5});
    auto test = select_subarray({-113,-157,193,-123,92,-109,70,-93,21,-97,-26,-188,124,-126,136,-159,-193,102,181,-162,101,153,-125,-73,13,-58,129,23,50,163,69,157,-1,126,45,56,-95,77,44,-150,103,-197,-169,90,172,-142,54,-5,-43,-147,123,75,-199,15,-128,-118,-91,198,-134,-152,162,-2,-85,175,25,-143,-53,97,-66,-176,145,127,-107,-115,94,93,-67,166,132,106,147,89,-104});
    std::cout << "Selected subarrays:" << std::endl;
    for (const auto& pair : test) {
        std::cout << "[" << pair.first << ", " << pair.second << "]" << std::endl;
    }

    //Expected: equal to "{52,-199}"
    //Actual: "{30,69}"
    // the q for 52 is higher than 30, so don't know
}
