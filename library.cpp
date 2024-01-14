/*
    library.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 14/01/2023
*/

#include <iostream>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "person.h"
#include "member.h"
#include "librarian.h"
#include "book.h"


std::vector<Book> loadBooks()
{
    std::vector<Book> books;
    bool validFileOpened = false;
    std::string filePath;

    std::ifstream inputFile;

    while (!validFileOpened) 
    {
        std::cout << "Enter the path of the CSV file: ";
        std::getline(std::cin, filePath);

        inputFile.open(filePath); // Open the file using the existing inputFile

        if (inputFile.is_open()) 
        {
            validFileOpened = true;
        } 
        else 
        {
            std::cerr << "Error opening the file. Please enter a valid path." 
                      << std::endl;
        }
    }

    std::string line;
    // Read and discard the first line (header)
    std::getline(inputFile, line); 

    while (std::getline(inputFile, line)) 
    {
        std::stringstream ss(line);
        std::string token;
        // Parse the CSV line
        std::vector<std::string> bookInfo;
        while (std::getline(ss, token, ',')) 
        {
            bookInfo.push_back(token);
        }
        // Check if the line has enough fields
        if (bookInfo.size() == 6) 
        {
            // Convert relevant fields to appropriate types
            int bookID = std::stoi(bookInfo[0]);
            std::string bookName = bookInfo[1];
            std::string authorFirstName = bookInfo[3];
            std::string authorLastName = bookInfo[4];
            std::string bookType = bookInfo[5];

            // Create a Book object and add it to the vector
            Book book(bookID, bookName, authorFirstName, authorLastName, 
                      bookType);
            books.push_back(book);
        } 
        else 
        {
            std::cerr << "Invalid line format: " << line << std::endl;
        }
    }

    // Close the file after using it
    inputFile.close();
    return books;
};

int menu()
{
    int choice;

    std::cout << "[1]Add a member" << std::endl;
    std::cout << "[2]Issue a book" << std::endl;
    std::cout << "[3]Return a book" << std::endl;
    std::cout << "[4]Display all books" << std::endl;
    std::cout << "[5]Calculate fine" << std::endl;
    std::cout << "[6]Exit" << std::endl;

    while (true) {
        std::cout << "Select a number: ";

        //validation
        if (std::cin >> choice && choice >= 1 && choice <= 6) 
        {
            break;
        } 
        else 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer between 1 and 6." 
                      << std::endl;
        }
    }

    return choice;
};

void addMember(std::vector<Member>& members)
{
    int memberID;
    std::string name, address, email;

    std::cout << "Enter Member ID: ";
    std::cin >> memberID;

    std::cout << "Enter Name: ";
    std::cin.ignore();  // Clear the newline character from the buffer
    std::getline(std::cin, name);

    std::cout << "Enter Address: ";
    std::getline(std::cin, address);

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    Member newMember(memberID, name, address, email);
    members.push_back(newMember);

    std::cout << "Member added successfully!\n";
}

void issueBook(std::vector<Member>& members, std::vector<Book>& books)
{
    int memberId, bookId;

    std::cout << "Enter Member ID and Book ID: ";
    std::cin >> memberId >> bookId;

    bool memberFound = false;
    bool bookFound = false;

    for (Member& member : members)
    {
        if (std::stoi(member.getMemberID()) == memberId)
        {
            for (Book& book : books)
            {
                if (book.getBookID() == bookId)
                {
                    member.setBooksBorrowed(book);
                    bookFound = true;
                    break;
                }
            }

            if (!bookFound)
            {
                std::cout << "Book not found." << std::endl;
            }

            memberFound = true;
        }
    }

    if (!memberFound)
    {
        std::cout << "Member not found." << std::endl;
    }
}

void returnBook(std::vector<Member>& members)
{
    int memberId, bookId;

    std::cout << "Enter Member ID and Book ID: ";
    std::cin >> memberId >> bookId;

    bool memberFound = false;
    bool bookFound = false;

    for (size_t i = 0; i < members.size(); ++i)
    {
        if (std::stoi(members[i].getMemberID()) == memberId)
        {
            for (size_t j = 0; j < members[i].getBooksBorrowed().size(); ++j)
            {
                if (members[i].getBooksBorrowed()[j].getBookID() == bookId)
                {
                    // Book found, remove it from the member's list
                    members[i].returnBook(bookId);
                    bookFound = true;
                }
            }

            if (!bookFound)
            {
                std::cout << "Book not issued to the member." << std::endl;
            }

            memberFound = true;
        }
    }

    if (!memberFound)
    {
        std::cout << "Member not found." << std::endl;
    }
}

void displayBook(std::vector<Member>& members)
{
    int memberId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;

    for (Member& member : members)
    {
        if (std::stoi(member.getMemberID()) == memberId)
        {
            std::cout << "Member ID: " << member.getMemberID() << std::endl;
            std::cout << "Name: " << member.getName() << std::endl;

            std::cout << "Books Borrowed: "<< std::endl;
            std::vector<Book>& borrowedBooks = member.getBooksBorrowed();
            for (Book& book : borrowedBooks)
            {
                std::cout << "Books ID "<< book.getBookID() << std::endl;
                std::cout << book.getBookName() << std::endl;
                std::cout << "***********************************" << std::endl;
            }
            std::cout << std::endl;

            return;
        }
    }

    // If the member with the specified ID is not found
    std::cout << "Member with ID " << memberId << " not found.\n";
}

void calculateFine()
{

};

void executeMenu(int opt, std::vector<Member>& members, std::vector<Book>& books)
{
    if (opt == 1) 
    {
        std::cout << "Executing option 1: Add a member" << std::endl;
        addMember(members);
    } 
    else if (opt == 2) 
    {
        std::cout << "Executing option 2: Issue a book" << std::endl;
        issueBook(members, books);
    } 
    else if (opt == 3) 
    {
        std::cout << "Executing option 3: Return a book" << std::endl;
        returnBook(members);
    } 
    else if (opt == 4) 
    {
        std::cout << "Executing option 4: Display all books borrowed by a member" 
                  << std::endl;
        displayBook(members);
    } 
    else if (opt == 5) 
    {
        std::cout << "Executing option 5: Calculate fine" << std::endl;
        calculateFine();
    } 
    else if (opt == 6) 
    {
        std::cout << "Exiting program" << std::endl;
        exit(0);
    }
}

int main()
{

    std::vector<Member> members;
    std::vector<Book> books = loadBooks();

    while (true) 
    {
        executeMenu(menu(), members, books);
    };

    return 0;
};