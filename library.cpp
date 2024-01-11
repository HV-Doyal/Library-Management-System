/*
    library.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 11/01/2023
*/

// basics person class test

#include <iostream>
#include "person.h"
#include "member.h"

int main()
{
    // Test for person class
    Person person("Kratos", "Playstation", "god@war.com");
    std::cout << "\nNamed Person Information:" << std::endl;
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Address: " << person.getAddress() << std::endl;
    std::cout << "Email: " << person.getEmail() << std::endl;

    // Test for member class
    Member member(0001, "Kratos", "Playstation", "god@war.com");
    std::cout << "Member ID: " << member.getMemberID() << std::endl;
    std::cout << "Name: " << member.getName() << std::endl;
    std::cout << "Address: " << member.getAddress() << std::endl;
    std::cout << "Email: " << member.getEmail() << std::endl;

    // Test for librarian class
    Librarian librarian(101, "Alice Librarian", "789 Main St", 
                        "alice.librarian@example.com", 50000);
    std::cout << "Staff ID: " << librarian.getStaffID() << std::endl;
    std::cout << "Name: " << librarian.getName() << std::endl;
    std::cout << "Address: " << librarian.getAddress() << std::endl;
    std::cout << "Email: " << librarian.getEmail() << std::endl;
    std::cout << "Salary: $" << librarian.getSalary() << std::endl;
    librarian.addMember();
    librarian.issueBook(1, 101);
    librarian.issueBook(2, 102);
    librarian.displayBorrowedBooks(1);
    librarian.returnBook(1, 101);
    librarian.calcFine(2);

    return 0;
}