/*
    member.cpp
    Author: M00953762
    Created: 09/01/2023
    Updated: 14/01/2023
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

void Member::returnBook(int bookId)
{
    std::vector<Book>::iterator it = std::remove_if(booksLoaned.begin(), 
                                                    booksLoaned.end(),
                                                    [bookId](Book& book) 
                                                    { return book.getBookID() 
                                                    == bookId; });

    // Check if the book was found
    if (it != booksLoaned.end())
    {
        // Erase the book from the vector
        booksLoaned.erase(it, booksLoaned.end());
        std::cout << "Book returned successfully." << std::endl;
    }
    else
    {
        std::cout << "Book not found in the member's borrowed books." << std::endl;
    }
}