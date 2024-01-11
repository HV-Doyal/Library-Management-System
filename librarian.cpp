/*
    librarian.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 09/01/2023
*/
#include "librarian.h"

Librarian::Librarian(int staffID, std::string name, std::string address, 
                     std::string email, int salary) 
                     : Person(name, address, email), 
                     staffID(staffID), salary(salary)
{
}

void Librarian::addMember()
{
    // Implement add a member
    std::cout << "Adding a member..." << std::endl;
}

void Librarian::issueBook(int memberID, int bookID)
{
    // Implement tissue a book to a member
    std::cout << "Issuing book " << bookID << " to member " << memberID 
              << std::endl;
    borrowedBooks.push_back(bookID);
}

void Librarian::returnBook(int memberID, int bookID)
{
    // Implement return a book from a member
    std::cout << "Returning book " << bookID << " from member " << memberID 
                                   << std::endl;
    // Remove the book from the borrowedBooks vector
    borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), 
                        bookID), borrowedBooks.end());
}

void Librarian::displayBorrowedBooks(int memberID)
{
    // Implement display borrowed books of a member
    std::cout << "Borrowed books by member " << memberID << ":" << std::endl;
    for (int bookID : borrowedBooks)
    {
        std::cout << "- Book " << bookID << std::endl;
    }
}

void Librarian::calcFine(int memberID)
{
    // Implement calculation fine for a member
    std::cout << "Calculating fine for member " << memberID << std::endl;
}

int Librarian::getStaffID()
{
    return staffID;
}

void Librarian::setStaffID(int staffID)
{
    this->staffID = staffID;
}

int Librarian::getSalary()
{
    return salary;
}

void Librarian::setSalary(int salary)
{
    this->salary = salary;
}
