#pragma once
#include <unordered_map>

class FibonnaciDP
{
public:
    std::unordered_map<int, int> memo;
    int fibonacci(int n);
    void Execute();
};
