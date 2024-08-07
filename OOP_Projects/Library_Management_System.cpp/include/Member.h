#pragma once

#include <string>
#include <vector>
#include "Book.h"
#include <iostream>
#include <memory>
#include <algorithm>

class Member {
    private:
        std::string name;
        int id;
        std::vector<std::shared_ptr<Book>> borrowedBooks;
    
    public:
        Member(const std::string& name, int id);
        
        std::string getName() const;
        int getId() const;
        void borrowBook(std::shared_ptr<Book> book);
        void returnBook(const std::string& isbn);
        std::vector<std::shared_ptr<Book>> getBorrowedBooks() const;
};
