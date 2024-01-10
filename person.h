#ifndef _PERSON_H_
#define _PERSON_H_

/*
    person.h
    Author: M00953762
    Created: 29/12/2023
    Updated: 10/01/2023
*/

#include <string>

class Person
{
    private:
        std::string name;
        std::string address;
        std::string email;

    public:

        void setName(std::string nm);
        
        std::string getName();

        void setAddress(std::string add);

        std::string getAddress();

        void setEmail(std::string eml);

        std::string getEmail();
};

#endif