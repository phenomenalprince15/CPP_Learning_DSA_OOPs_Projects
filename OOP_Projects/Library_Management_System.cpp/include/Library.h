#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Member.h"
#include "Book.h"
#include "Transaction.h"

class Library {
    private:
        std::vector<std::shared_ptr<Book>> books;
        std::vector<std::shared_ptr<Member>> members;
        std::vector<Transaction> transactions;
    
    public:
        void addBook(std::shared_ptr<Book> book);
        void removeBook(const std::string &isbn);
        std::shared_ptr<Book> findBookByISBN(const std::string& isbn) const;
        std::vector<std::shared_ptr<Book>> searchBookByTitle(const std::string& title) const;
        
        void registerMember(std::shared_ptr<Member> member);
        void removeMember(int memberId);
        std::shared_ptr<Member> findMemberById(int memberId) const;

        void borrowBook(int memberId, const std::string& isbn);
        void returnBook(int memberId, const std::string& isbn);

        std::vector<std::shared_ptr<Book>> getAllBooks() const;
        std::vector<std::shared_ptr<Member>> getAllMembers() const;

        void saveData() const;
        void loadData();
};
