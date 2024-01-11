#ifndef _BOOK_H_
#define _BOOK_H_
/*
    book.h
    Author: M00953762
    Created: 29/12/2023
    Updated: 29/12/2023
*/

#include <string>
#include "member.h"
#include "librarian.h"

class Date;  // Forward declaration of the Date class

class Book
{
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    Date *dueDate;
    Member *borrower;

public:
    Book(int bookID, std::string bookName, std::string authorFirstName, 
         std::string authorLastName, std::string bookType);

    int getBookID();
    std::string getBookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
    Date getDueDate();

    void setDueDate(Date dueDate);
    void returnBook();
    void borrowBook(Member *borrower, Date dueDate);
};

#endif