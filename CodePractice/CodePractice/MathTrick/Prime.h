#pragma once
#include <cstdint>
#include <vector>

class Prime
{
public:
    int gcd(int a, int b);
    bool IsACoprimeOf(int Value, int Coprime);
    uint64_t generateHammingNumbers(int n);
    std::vector<int> generatePrimes(int n);
};
