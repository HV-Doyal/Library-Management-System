/*
    library.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 09/01/2023
*/

// basics person class test

#include <iostream>
#include "person.h"

int main()
{
    // Create a Person object
    Person person;

    // Set values using member functions
    person.setName("Kratos");
    person.setAddress("Playstation");
    person.setEmail("god@war.com");

    // Display information using member functions
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Address: " << person.getAddress() << std::endl;
    std::cout << "Email: " << person.getEmail() << std::endl;

    return 0;
}