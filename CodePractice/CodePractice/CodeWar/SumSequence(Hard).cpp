#include <iostream>
#include "SumSequence(Hard).h"

//https://www.codewars.com/kata/587a88a208236efe8500008b/train/cpp
long long int SumSequence_Hard_::sequence_sum(long long int begin_number, long long int end_number, long long step)
{
    long long int answer = 0;
    if (begin_number <= end_number && step > 0)
    {
        for (long long int i=begin_number; i<=end_number; i += step)
        {
            answer += i;
        }
    }
    else if (begin_number >= end_number && step < 0)
    {
        for (long long int i=begin_number; i>=end_number; i += step)
        {
            answer += i;
        }
    }
    return answer;
}

void SumSequence_Hard_::Execute()
{
    std::cout<< sequence_sum(1,5,3) << std::endl; //5
}
