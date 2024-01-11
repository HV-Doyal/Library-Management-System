/*
    member.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 11/01/2023
*/
#include "member.h"
#include "book.h"  

Member::Member(int memberID, std::string name, std::string address, 
               std::string email) : Person(name, address, email), 
               memberID(memberID)
{

}

std::string Member::getMemberID()
{
    return std::to_string(memberID);
}

std::vector<Book>& Member::getBooksBorrowed() 
{
    return booksLoaned;
}

void Member::setBooksBorrowed(Book& book)
{
    booksLoaned.push_back(book);
}