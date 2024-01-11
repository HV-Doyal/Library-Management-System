/*
    library.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 11/01/2023
*/

#include "person.h"
#include "member.h"
#include "librarian.h"
#include "book.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void clearConsole()
{
#ifdef _WIN32
    // For Windows
    system("cls");
#elif __linux__
    // For Linux
    system("clear");
#elif __APPLE__
    // For macOS
    system("clear");
#else
    // Unsupported platform
    std::cout << "Console clearing not supported on this platform." << std::endl;
#endif
}

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

void executeMenu(int opt)
{
    clearConsole();
     if (opt == 1) 
     {
        std::cout << "Executing option 1: Add a member" << std::endl;
        // Add member logic here
    } 
    else if (opt == 2) 
    {
        std::cout << "Executing option 2: Issue a book" << std::endl;
        // Issue book logic here
    } 
    else if (opt == 3) 
    {
        std::cout << "Executing option 3: Return a book" << std::endl;
        // Return book logic here
    } 
    else if (opt == 4) 
    {
        std::cout << "Executing option 4: Display all books" << std::endl;
        // Display books logic here
    } 
    else if (opt == 5) 
    {
        std::cout << "Executing option 5: Calculate fine" << std::endl;
        // Calculate fine logic here
    } 
    else if (opt == 6) 
    {
        std::cout << "Exiting program" << std::endl;
        exit(0);
    } 
}

int main()
{
  executeMenu(menu());
};