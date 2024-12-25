#include "FibonnaciDP.h"

#include <iostream>
#include <ostream>

int FibonnaciDP::fibonacci(int n)
{
    if (n <= 1) return n;
    
    if (memo.find(n) != memo.end()) {
        return memo[n];  // Return cached result
    }
    
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);  // Cache the result
    return memo[n];
}

void FibonnaciDP::Execute()
{
    std::cout << fibonacci(10) << std::endl;
}
