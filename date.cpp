/*
    date.cpp
    Author: M00953762
    Created: 11/01/2023
    Updated: 11/01/2023
*/

#include <iostream>
#include "date.h"

int main() 
{
    // Creating instances of the Date class
    Date date1(13, 8, 2029);
    Date date2(1, 12, 2026);

    // Comparing dates
    if (date1 < date2) 
    {
        std::cout << date1 << " is earlier than " << date2 << std::endl;
    } 
    else 
    {
        std::cout << date2 << " is earlier than " << date1 << std::endl;
    }

    return 0;
}