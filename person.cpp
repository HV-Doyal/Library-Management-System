/*
    person.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 09/01/2023
*/

#include "person.h"

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
