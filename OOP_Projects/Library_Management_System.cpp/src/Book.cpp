#include "Book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {
            available = true;
        }

std::string Book::getTitle() const{
    return title;
}

std::string Book::getAuthor() const{
    return author;
}

std::string Book::getISBN() const{
    return isbn;
}

bool Book::isAvailable() const{
    return available;
}

void Book::setAvailablity(bool available){
    this->available = available;
}
