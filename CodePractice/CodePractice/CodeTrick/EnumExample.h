#pragma once
// Define an enum for days of the week
enum class DayOfWeek {
    Sunday,    // 0
    Monday,    // 1
    Tuesday,   // 2
    Wednesday, // 3
    Thursday,  // 4
    Friday,    // 5
    Saturday   // 6
};

class EnumExample
{
public:
    void printDay(DayOfWeek day);
    void Execute();
};
