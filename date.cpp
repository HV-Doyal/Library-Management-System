/*
    date.cpp
    Author: M00953762
    Created: 11/01/2023
    Updated: 11/01/2023
*/

#include "date.h"

Date::Date(int day, int month, int year) 
{
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