/*
    library.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 09/01/2023
*/

// basics person class test

#include <iostream>
#include "person.h"
#include "member.h"

int main()
{
    // Test for person class
    Person person("Kratos", "Playstation", "god@war.com");
    std::cout << "\nNamed Person Information:" << std::endl;
    std::cout << "Name: " << namedPerson.getName() << std::endl;
    std::cout << "Address: " << namedPerson.getAddress() << std::endl;
    std::cout << "Email: " << namedPerson.getEmail() << std::endl;

    // Test for member class
    Member member(0001, "Kratos", "Playstation", "god@war.com");
    std::cout << "Member ID: " << member.getMemberID() << std::endl;
    std::cout << "Name: " << member.getName() << std::endl;
    std::cout << "Address: " << member.getAddress() << std::endl;
    std::cout << "Email: " << member.getEmail() << std::endl;

    return 0;
}