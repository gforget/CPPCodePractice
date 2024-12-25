#include "Lucas numbers.h"

#include <iostream>

long long int Lucas_numbers::lucasnum(int n)
{
    if (n == 0) return 2;
    if (n == 1) return 1;

    //if you already calculated that n, just repeat it
    if (memo.find(n) != memo.end())
    {
        return memo[n];
    }
    
    if (n >= 2) 
    {
        memo[n] = lucasnum(n-1) + lucasnum(n-2);  
    }
    else if (n < 0)
    {
        memo[n] = lucasnum(n+2) - lucasnum(n+1);
    }
    
    return memo[n];
}

void Lucas_numbers::Execute()
{
    std::cout<< lucasnum(100) <<std::endl;
}
