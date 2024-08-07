#include <iostream>
#include <memory>
#include "Library.h"
#include "nlohmann/json.hpp"


using json = nlohmann::json;

void printMenu() {
    std::cout << "Library Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Register Member\n";
    std::cout << "3. Borrow Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. View Available Books\n";
    std::cout << "6. View Member Info\n";
    std::cout << "7. Save and Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    Library library;

    library.loadData(); // Load data from JSON files

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string title, author, isbn;
                std::cout << "Enter title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, isbn);
                library.addBook(std::make_shared<Book>(title, author, isbn));
                break;
            }
            case 2: {
                std::string name;
                int id;
                std::cout << "Enter name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter ID: ";
                std::cin >> id;
                library.registerMember(std::make_shared<Member>(name, id));
                break;
            }
            case 3: {
                int memberId;
                std::string isbn;
                std::cout << "Enter member ID: ";
                std::cin >> memberId;
                std::cout << "Enter book ISBN: ";
                std::cin.ignore();
                std::getline(std::cin, isbn);
                library.borrowBook(memberId, isbn);
                break;
            }
            case 4: {
                int memberId;
                std::string isbn;
                std::cout << "Enter member ID: ";
                std::cin >> memberId;
                std::cout << "Enter book ISBN: ";
                std::cin.ignore();
                std::getline(std::cin, isbn);
                library.returnBook(memberId, isbn);
                break;
            }
            case 5: {
                std::cout << "Available books:\n";
                for (const auto& book : library.getAllBooks()) {
                    if (book->isAvailable()) {
                        std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor()
                                  << ", ISBN: " << book->getISBN() << "\n";
                    }
                }
                break;
            }
            case 6: {
                std::cout << "Member information:\n";
                for (const auto& member : library.getAllMembers()) {
                    std::cout << "Name: " << member->getName() << ", ID: " << member->getId() << "\n";
                    std::cout << "Borrowed books:\n";
                    for (const auto& book : member->getBorrowedBooks()) {
                        std::cout << " - Title: " << book->getTitle() << ", Author: " << book->getAuthor()
                                  << ", ISBN: " << book->getISBN() << "\n";
                    }
                }
                break;
            }
            case 7: {
                library.saveData(); // Save data to JSON files
                std::cout << "Data saved. Exiting...\n";
                break;
            }
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 7);

    return 0;
}
