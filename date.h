#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date 
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) 
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool operator<(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

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

#endif
