/*
    date.cpp
    Author: M00953762
    Created: 11/01/2023
    Updated: 11/01/2023
*/

#include "date.h"

Date::Date(int day, int month, int year) 
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) 
    {
        std::cerr << "Invalid date input. Setting default values." << std::endl;
        day = 1;
        month = 1;
        year = 2000;
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const 
{ 
    return day; 
}

int Date::getMonth() const 
{ 
    return month; 
}

int Date::getYear() const 
{ 
    return year; 
}

bool Date::operator<(const Date& other) const 
{
    if (year < other.getYear()) 
    {
        return true;
    }
    else if (year == other.getYear() && month < other.getMonth()) 
    {
        return true;
    }
    else if (year == other.getYear() && month == other.getMonth() && day < other.getDay()) 
    {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Date& date) 
{
    out << date.getDay() << '-' << date.getMonth() << '-' << date.getYear();
    return out;
}