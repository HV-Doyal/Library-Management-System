#ifndef _PERSON_H_
#define _PERSON_H_
/*
    person.h
    Author: M00953762
    Created: 29/12/2023
    Updated: 29/12/2023
*/

#include <string>

class Person
{
    private:
        std::string name;
        std::string address;
        std::string email;
    
    public:
        void setName(std::string nm)
        {
            name = nm;
        }
        std::string getName()
        {
            return name;
        }

        void setAddress(std::string add)
        {
            address = add;
        }

        std::string getAddress()
        {
            return address;
        }

        void setEmail(std::string eml)
        {
            email = eml;
        }

        std::string getEmail()
        {
            return email;
        }
};

#endif