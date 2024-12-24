#pragma once
#include <cstdint>

class Prime
{
public:
    int gcd(int a, int b);
    bool IsACoprimeOf(int Value, int Coprime);
    uint64_t generateHammingNumbers(int n);
};
