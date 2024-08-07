#pragma once
#include <string>
#include <memory>
#include <ctime>

#include "Book.h"
#include "Member.h"

class Transaction {
    private:
        std::shared_ptr<Member> member;
        std::shared_ptr<Book> book;
        std::time_t date;
        bool borrowing;
    
    public:
        Transaction(std::shared_ptr<Member> member, std::shared_ptr<Book> book, const std::time_t& date,
                    bool isBorrowing);
        
        std::shared_ptr<Member> getMember() const;
        std::shared_ptr<Book> getBook() const;
        std::time_t getDate() const;
        bool isBorrowing() const;
};

