#include "ErrorHistogram.h"

#include <iostream>
#include <map>

std::string ErrorHistogram::hist(const std::string& s)
{
    // map every error char found
    std::map<char,int> ErrorMap;
    ErrorMap['u'] = static_cast<int>(std::count(s.begin(), s.end(), 'u'));
    ErrorMap['w'] = static_cast<int>(std::count(s.begin(), s.end(), 'w'));
    ErrorMap['x'] = static_cast<int>(std::count(s.begin(), s.end(), 'x'));
    ErrorMap['z'] = static_cast<int>(std::count(s.begin(), s.end(), 'z'));
    
    //generate the string report
    std::string report;
    for (const auto& pair : ErrorMap)
    {
        if (pair.second > 0)
        {
            //error character field
            report += pair.first;
            report.append("  ");

            //number field
            std::string NbErrorString = std::to_string(pair.second);
            std::string NumberField = "      ";
            for (int i=0; i<NbErrorString.size(); i++)
            {
                NumberField[i] = NbErrorString[i];
            }
            report.append(NumberField);

            for (int i=0; i<pair.second; i++)
            {
                report += '*';
            }
            
            report.append("\\r");
        }
    }
    
    if (!report.empty())
    {
        report.resize(report.size()-2);
    }

    return report;
}

void ErrorHistogram::Execute()
{
    std::cout<< hist("tpaemqdmqbqrjbeosjnejqordosnrgpgqkeihqybyymqeafkyicestgsbenvgibrlvmihcb") << std::endl;
}
