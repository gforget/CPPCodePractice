#include "COut.h"

#include <iostream>
#include <string>

void COut::Execute()
{
    std::string stringvar = "hello world";
    char charvar = 'a';
    int intvar = 10;
    float floatvar = 10.0f;
    double doublevar = 10.0f;
    long longvar = 10.0f;
    long long longlongvar = 10.0f;
    
    std::cout << stringvar << " " << intvar << std::endl;
    std::cout << charvar << std::endl;
    std::cout << intvar << std::endl;
    std::cout << floatvar << std::endl;
    std::cout << doublevar << std::endl;
    std::cout << longvar << std::endl;
    std::cout << longlongvar << std::endl;
}
