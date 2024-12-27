#include "EnumExample.h"

#include <iostream>

void EnumExample::printDay(DayOfWeek day)
{
    switch (day) {
        case DayOfWeek::Sunday:
            std::cout << "Sunday\n";
            break;
        case DayOfWeek::Monday:
            std::cout << "Monday\n";
            break;
        case DayOfWeek::Tuesday:
            std::cout << "Tuesday\n";
            break;
        case DayOfWeek::Wednesday:
            std::cout << "Wednesday\n";
            break;
        case DayOfWeek::Thursday:
            std::cout << "Thursday\n";
            break;
        case DayOfWeek::Friday:
            std::cout << "Friday\n";
            break;
        case DayOfWeek::Saturday:
            std::cout << "Saturday\n";
            break;
    }
}

void EnumExample::Execute()
{
        DayOfWeek today = DayOfWeek::Tuesday;

        std::cout << "Today is: ";
        printDay(today);
}
