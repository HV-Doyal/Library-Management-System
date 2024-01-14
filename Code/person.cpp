/*
    person.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 11/01/2023
*/

#include "person.h"

Person::Person(std::string name, std::string address, std::string email)
    : name(name), address(address), email(email) {}

void Person::setName(std::string nm)
{
    this->name = nm;
}

std::string Person::getName()
{
    return this->name;
}

void Person::setAddress(std::string add)
{
    this->address = add;
}

std::string Person::getAddress()
{
    return this->address;
}

void Person::setEmail(std::string eml)
{
    this->email = eml;
}

std::string Person::getEmail()
{
    return this->email;
}
