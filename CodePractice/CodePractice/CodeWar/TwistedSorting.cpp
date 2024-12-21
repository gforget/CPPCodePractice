#include "TwistedSorting.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void TwistedSorting::Execute()
{
    //https://www.codewars.com/kata/58068479c27998b11900056e/train/cpp
    std::vector<int> numbers = {1,2,3,4,5,6,7,8,9};
    
    auto SortAscAndSwap37= [](const int a, const int b)
    {
        std::string Astr = std::to_string(a);
        std::string Bstr = std::to_string(b);
    
        for (char& ch : Astr) 
        {
            if (ch == '3' || ch == '7') ch = ch == '7' ? '3' : '7';
        }
    
        for (char& ch : Bstr)
        {
            if (ch == '3' || ch == '7') ch = ch =='7' ? '3' : '7';
        }
        
        int EvalA = std::stoi(Astr);
        int EvalB = std::stoi(Bstr);
        return EvalA < EvalB;  
    };

    std::vector<int> result = numbers;
    std::sort(result.begin(), result.end(), SortAscAndSwap37);

    for (int i=0; i<result.size(); i++)
    {
        std::cout  << result[i] << ", ";
    }
}
