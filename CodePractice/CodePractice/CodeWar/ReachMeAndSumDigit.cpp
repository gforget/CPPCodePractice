#include "ReachMeAndSumDigit.h"

#include <iostream>
#include <string>

//https://www.codewars.com/kata/55ffb44050558fdb200000a4/train/cpp
int ReachMeAndSumDigit::sumDigNthTerm(int initval, const std::vector<int> patternl, int nthterm)
{
    int pattern_index = 0;
    for (int i=1; i<nthterm; i++)
    {
        initval += patternl[pattern_index];
        pattern_index++;
        if (pattern_index == static_cast<int>(patternl.size())) pattern_index = 0;
    }

    std::string valstring = std::to_string(initval);

    int sumdigit = 0;
    for (int i=0; i<valstring.size(); i++)
    {
        sumdigit += valstring[i] - '0'; //trick to convert a char into an int
    }
    
    return sumdigit;
}

void ReachMeAndSumDigit::Execute()
{
    std::vector<int> patternl = {2, 1, 3};
    std::cout<< sumDigNthTerm(10, patternl, 6) << std::endl;
}
