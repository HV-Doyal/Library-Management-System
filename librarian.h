#ifndef _LIBRARIAN_H_
#define _LIBRARIAN_H_
/*
    librarian.h
    Author: M00953762
    Created: 29/12/2023
    Updated: 11/01/2023
*/

#include "person.h"
#include <iostream>
#include <vector>

class Librarian : public Person
{
    private:
        int staffID;
        int salary;
    public:
        Librarian(int staffID, std::string name, std::string address, 
                  std::string email, int salary);
        void addMember();
        void issueBook(int memberID, int bookID);
        void returnBook(int memberID, int bookID);
        void displayBorrowedBooks(int memberID);
        void calcFine(int memberID);
        int getStaffID();
        void setStaffID(int staffID);
        int getSalary();
        void setSalary(int salary);
};

#endif