#ifndef _MEMBER_H_
#define _MEMBER_H_
/*
    member.h
    Author: M00953762
    Created: 29/12/2023
    Updated: 14/01/2023
*/

#include "person.h"
#include <vector>
#include <algorithm>

class Book;

class Member : public Person 
{
   private:
    int memberID;
    std::vector<Book> booksLoaned;

    public:
        Member(int memberID, std::string name, std::string address,
               std::string email);

        std::string getMemberID();

        std::vector<Book>& getBooksBorrowed();

        void setBooksBorrowed(Book& book);

        void returnBook(int bookId);
};

#endif