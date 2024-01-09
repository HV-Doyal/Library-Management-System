#ifndef _MEMBER_H_
#define _MEMBER_H_
/*
    member.h
    Author: M00953762
    Created: 29/12/2023
    Updated: 07/01/2023
*/

#include "person.h"
#include <vector>

class Book

class Member : public Person 
{
    private:
        int memberId;
        std::vector<Book*> borrowedBooks;

    public:
        Member(std::string name, std::string address, std::string email,
               int memberId);
        ~Member();
        std::string getMemberID()
        {
            return memberId;
        }
        std::vector getBooksBorrowed()
        {
            return borrowedBooks;
        }
        void setBooksBorrowed(Book* book);

};

#endif