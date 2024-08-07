#include "Member.h"

Member::Member(const std::string& name, int id)
        : name(name), id(id) {}

std::string Member::getName() const{
    return name;
}

int Member::getId() const{
    return id;
}

void Member::borrowBook(std::shared_ptr<Book> book){
    borrowedBooks.push_back(book);
    book->setAvailablity(false);
}

void Member::returnBook(const std::string& isbn){
    borrowedBooks.erase(std::remove_if(borrowedBooks.begin(), borrowedBooks.end(), 
        [&](const std::shared_ptr<Book>& book){
            if (book->getISBN() == isbn) {
                book->setAvailablity(true);
                return true;
            }
            return false;
        }), borrowedBooks.end());
}

std::vector<std::shared_ptr<Book>> Member::getBorrowedBooks() const{
    return borrowedBooks;
}
