#pragma once
#include <functional>
#include <vector>

class Predicate
{
    
public:
    bool IsEven(int x);
    
    template <typename Predicate>
    int filterAndCount(const std::vector<int>& vec, Predicate pred);

    std::vector<int> AllValid(const std::vector<int>& vec, std::function<bool (int)> pred);
    
    void Execute();
};


