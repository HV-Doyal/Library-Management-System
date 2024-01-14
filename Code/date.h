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
    Date(int day, int month, int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    bool operator<(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

#endif