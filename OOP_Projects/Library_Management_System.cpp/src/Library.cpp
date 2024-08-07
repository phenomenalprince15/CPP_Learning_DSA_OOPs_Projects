#include "Library.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>


void Library::addBook(std::shared_ptr<Book> book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& isbn) {
    books.erase(std::remove_if(books.begin(), books.end(),
        [&](const std::shared_ptr<Book> &book){
            return book->getISBN() == isbn;
        }), books.end());
}

std::shared_ptr<Book> Library::findBookByISBN(const std::string& isbn) const {
    auto it = std::find_if(books.begin(), books.end(),
        [&](const std::shared_ptr<Book> &book){
            return book->getISBN() == isbn;
        });
    
    if (it != books.end()) return *it;
    return nullptr;
}

std::vector<std::shared_ptr<Book>> Library::searchBookByTitle(const std::string& title) const {
    std::vector<std::shared_ptr<Book>> results;
    for (const auto &book : books) {
        if (book->getTitle().find(title) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

void Library::registerMember(std::shared_ptr<Member> member) {
    members.push_back(member);
}

void Library::removeMember(int memberId) {
    members.erase(std::remove_if(members.begin(), members.end(),
        [&](const std::shared_ptr<Member> member){
            return member->getId() == memberId;
        }), members.end());
}
std::shared_ptr<Member> Library::findMemberById(int memberId) const {
    auto it = std::find_if(members.begin(), members.end(),
        [&](const std::shared_ptr<Member> &member){
            return member->getId() == memberId;
        });
    
    if (it != members.end()) return *it;
    return nullptr;
}

void Library::borrowBook(int memberId, const std::string& isbn) {
    auto member = findMemberById(memberId);
    auto book = findBookByISBN(isbn);

    if (member && book && book->isAvailable()){
        member->borrowBook(book);
        transactions.emplace_back(member, book, std::time(nullptr), true);
    } else {
        std::cout << "Book is not available or member does not exist.\n";
    }
}

void Library::returnBook(int memberId, const std::string& isbn) {
    auto member = findMemberById(memberId);
    auto book = findBookByISBN(isbn);

    if (member && book) {
        member->returnBook(isbn);
        transactions.emplace_back(member, book, std::time(nullptr), false);
    } else {
        std::cout << "Book or member does not exist.\n";
    } 
}

std::vector<std::shared_ptr<Book>> Library::getAllBooks() const {
    return books;
}

std::vector<std::shared_ptr<Member>> Library::getAllMembers() const {
    return members;
}

void Library::saveData() const {
    nlohmann::json jsonBooks, jsonMembers, jsonTransactions;

    for (const auto& book : books) {
        jsonBooks.push_back({
            {"title", book->getTitle()},
            {"author", book->getAuthor()},
            {"isbn", book->getISBN()},
            {"available", book->isAvailable()}
        });
    }

    for (const auto& member : members) {
        jsonMembers.push_back({
            {"name", member->getName()},
            {"id", member->getId()},
            {"borrowed_books", {}}
        });

        for (const auto& borrowedBook : member->getBorrowedBooks()) {
            jsonMembers.back()["borrowed_books"].push_back(borrowedBook->getISBN());
        }
    }

    for (const auto& transaction : transactions) {
        jsonTransactions.push_back({
            {"member_id", transaction.getMember()->getId()},
            {"book_isbn", transaction.getBook()->getISBN()},
            {"date", static_cast<int>(transaction.getDate())},
            {"borrowing", transaction.isBorrowing()}
        });
    }

    std::ofstream bookOut("../data/books.json");
    if (bookOut.is_open()) {
        bookOut << jsonBooks.dump(4);
    } else {
        std::cerr << "Error: Could not open books.json file for writing!" << std::endl;
    }

    std::ofstream memberOut("../data/members.json");
    if (memberOut.is_open()) {
        memberOut << jsonMembers.dump(4);
    } else {
        std::cerr << "Error: Could not open members.json file for writing!" << std::endl;
    }

    std::ofstream transactionOut("../data/transactions.json");
    if (transactionOut.is_open()) {
        transactionOut << jsonTransactions.dump(4);
    } else {
        std::cerr << "Error: Could not open transactions.json file for writing!" << std::endl;
    }
}


void Library::loadData() {
    std::ifstream bookFile("../data/books.json");
    std::ifstream memberFile("../data/members.json");
    std::ifstream transactionFile("../data/transactions.json");

    nlohmann::json jsonBooks, jsonMembers, jsonTransactions;

    if (bookFile.is_open()) {
        bookFile >> jsonBooks;
    } else {
        std::cerr << "Error: Could not open books.json file!" << std::endl;
        jsonBooks = nlohmann::json::array(); // Initialize as an empty array
    }

    if (memberFile.is_open()) {
        memberFile >> jsonMembers;
    } else {
        std::cerr << "Error: Could not open members.json file!" << std::endl;
        jsonMembers = nlohmann::json::array(); // Initialize as an empty array
    }

    if (transactionFile.is_open()) {
        transactionFile >> jsonTransactions;
    } else {
        std::cerr << "Error: Could not open transactions.json file!" << std::endl;
        jsonTransactions = nlohmann::json::array(); // Initialize as an empty array
    }

    // Process books
    for (const auto& item : jsonBooks) {
        addBook(std::make_shared<Book>(item["title"], item["author"], item["isbn"]));
        auto book = findBookByISBN(item["isbn"]);
        if (book) {
            book->setAvailablity(item["available"]);
        }
    }

    // Process members
    for (const auto& item : jsonMembers) {
        auto member = std::make_shared<Member>(item["name"], item["id"]);
        registerMember(member);

        for (const auto& isbn : item["borrowed_books"]) {
            auto book = findBookByISBN(isbn);
            if (book) {
                member->borrowBook(book);
            }
        }
    }

    // Process transactions
    for (const auto& item : jsonTransactions) {
        auto member = findMemberById(item["member_id"]);
        auto book = findBookByISBN(item["book_isbn"]);

        if (member && book) {
            transactions.emplace_back(member, book, item["date"], item["borrowing"]);
        }
    }
}



