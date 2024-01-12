/*
    library.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 12/01/2023
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

void printMemberByID(std::vector<Member>& members, int targetMemberID)
{
    for (Member& member : members)
    {
        if (std::stoi(member.getMemberID()) == targetMemberID)
        {
            std::cout << "Member ID: " << member.getMemberID() << std::endl;
            std::cout << "Name: " << member.getName() << std::endl;
            std::cout << "Address: " << member.getAddress() << std::endl;
            std::cout << "Email: " << member.getEmail() << std::endl;

            // Print borrowed books if needed
            std::cout << "Books Borrowed: ";
            std::vector<Book>& borrowedBooks = member.getBooksBorrowed();
            for (Book& book : borrowedBooks)
            {
                std::cout << book.getBookName() << ", ";
            }
            std::cout << std::endl;

            return;
        }
    }

    // If the member with the specified ID is not found
    std::cout << "Member with ID " << targetMemberID << " not found.\n";
}

void issueBook()
{

};

void returnBook()
{

};

void displayBook()
{
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

    std::vector<Book> books;

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

    // Example: Print book information using only the ID
    int searchID;
    std::cout << "Enter the Book ID to search: ";
    std::cin >> searchID;

    // Search for the book with the specified ID
    for (size_t i = 0; i < books.size(); ++i) 
    {
        if (books[i].getBookID() == searchID) 
        {
            // Print book information
            std::cout << "Book Information:" << std::endl;
            std::cout << "ID: " << books[i].getBookID() << std::endl;
            std::cout << "Name: " << books[i].getBookName() << std::endl;
            std::cout << "Author: " << books[i].getAuthorFirstName() << " " 
                      << books[i].getAuthorLastName() << std::endl;
            break;
        }
    }

    // Close the file after using it
    inputFile.close();
}

void calculateFine()
{

};

void executeMenu(int opt)
{
    std::vector<Member> members;
    if (opt == 1) 
    {
        std::cout << "Executing option 1: Add a member" << std::endl;
        addMember(members);
    } 
    else if (opt == 2) 
    {
        std::cout << "Executing option 2: Issue a book" << std::endl;
        issueBook();
    } 
    else if (opt == 3) 
    {
        std::cout << "Executing option 3: Return a book" << std::endl;
        returnBook();
    } 
    else if (opt == 4) 
    {
        std::cout << "Executing option 4: Display all books borrowed by a member" 
                  << std::endl;
        displayBook();
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

  //executeMenu(menu());
  //displayBook();
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  addMember(members);

  int targetMemberID;
    std::cout << "Enter Member ID to print: ";
    std::cin >> targetMemberID;

    printMemberByID(members, targetMemberID);

  return 0;
};