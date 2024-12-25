#pragma once
#include <unordered_map>

class Lucas_numbers
{
public:

    std::unordered_map<long long int, long long int> memo;
    
    long long int lucasnum(int n);
    void Execute();
};
