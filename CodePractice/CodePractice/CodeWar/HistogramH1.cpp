#include "HistogramH1.h"

std::string HistogramH1::Execute(std::vector<int> results)
{
    //https://www.codewars.com/kata/57d532d2164a67cded0001c7
    //std::string actual = histogram({ 7, 3, 10, 1, 0, 5 });

    std::string AnswerString;
    
    //start from 6 to 1
    for (int i=5; i>=0; i--)
    {
        AnswerString.append(std::to_string(i+1));
        AnswerString.append("|");
        
        for (int j=0; j<results[i]; j++)
        {
            AnswerString.append("#");
        }

        if (results[i] > 0)
        {
            AnswerString.append(" ");
            AnswerString.append(std::to_string(results[i]));
        }
        
        AnswerString.append("\n");
    }

    std::vector<int> result;
    
    return AnswerString;
}
