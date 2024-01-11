/*
    member.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 11/01/2023
*/
#include "member.h"
#include "book.h"  

Member::Member(int memberID, std::string name, std::string address, std::string email)
    : Person(name, address, email), memberID(memberID)

int Member::getMemberID() const
{
    return memberID;
}

const std::vector<Book>& Member::getBooksBorrowed() const
{
    return booksLoaned;
}

void Member::setBooksBorrowed(const Book& book)
{
    booksLoaned.push_back(book);
}