#include "LatinPig.h"

#include <iostream>
#include <sstream>
#include <vector>

std::string LatinPig::pig_it(std::string str)
{
    //split each word seperated by a space into an array of string
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word)
    {
        words.push_back(word);    
    }

    std::string result;
    //parse through the array of word
    for (int i=0; i<words.size(); i++)
    {
        bool isPunctuation = false;
        //put the first letter at the end of the word, if the word is bigger than one letter
        if (words[i].length() > 1)
        {
            char firstChar = words[i][0];
            words[i] = words[i].substr(1) + firstChar;   
        }
        else
        {
            //verify if it is a punctuation
            if (std::ispunct(words[i][0]))
            {
                isPunctuation = true;
            }
        }
        
        //add ay at the end
        if (!isPunctuation)
        {
            words[i].append("ay");
        }
        
        //reconstruct a result string with a space between the words
        result.append(words[i]);

        if (i < words.size()-1)
        {
            result.append(" ");
        }
    }

    return result;
}

void LatinPig::Execute()
{
    std::cout << pig_it("This is my string") << std::endl;
}
