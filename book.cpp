/*
    book.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 09/01/2023
*/
#include "book.h"
#include "date.h"

Book::Book(int bookID, std::string bookName, std::string authorFirstName,
           std::string authorLastName, std::string bookType)
           : bookID(bookID), bookName(bookName),
           authorFirstName(authorFirstName), authorLastName(authorLastName),
           bookType(bookType), dueDate(), borrower()
{
}

int Book::getBookID() const
{
    return bookID;
}

std::string Book::getBookName() const
{
    return bookName;
}

std::string Book::getAuthorFirstName() const
{
    return authorFirstName;
}

std::string Book::getAuthorLastName() const
{
    return authorLastName;
}

Date Book::getDueDate() const
{
    return dueDate;
}

void Book::setDueDate(const Date& dueDate)
{
    this->dueDate = dueDate;
}

void Book::returnBook()
{
    if (borrower != nullptr)
    {
        std::cout << "Returning book " << bookID << " from "
                  << borrower->getName() << std::endl;
        borrower = nullptr;
    }
    else
    {
        std::cout << "Book " << bookID << " is not currently borrowed."
                  << std::endl;
    }
}

void Book::borrowBook(Member* borrower, const Date& dueDate)
{
    if (this->borrower == nullptr)
    {
        this->borrower = borrower;
        this->dueDate = dueDate;
        std::cout << borrower->getName() << " borrowed book " << bookID
                  << " with due date " << dueDate << std::endl;
    }
    else
    {
        std::cout << "Book " << bookID << " is already borrowed." << std::endl;
    }
}
