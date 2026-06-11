#include "DayMonYear.h"




DayMonYear::DayMonYear(int daySet, int monthSet, int yearSet, std::string title, std::string description) {

    day = daySet;
    month = monthSet;
    year = yearSet;

    titleTask = title;
    descriptionTask = description;


}


bool DayMonYear::check() const
{
    if (month < 1 || month > 12)
        return false;

    if (day < 1)
        return false;

    int daysInMonth[] = {
        31, // Jan
        28, // Feb
        31, // Mar
        30, // Apr
        31, // May
        30, // Jun
        31, // Jul
        31, // Aug
        30, // Sep
        31, // Oct
        30, // Nov
        31  // Dec
    };

    // Leap year adjustment for February
    bool leapYear =
        (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);

    if (leapYear)
        daysInMonth[1] = 29;

    return day <= daysInMonth[month - 1];
}
