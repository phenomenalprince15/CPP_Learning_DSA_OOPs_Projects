# Project Statement: Library Management System
## Overview:
Create a Library Management System that manages books, members, and borrowing transactions. The system will allow users to add books, register members, borrow and return books, and view borrowing history. The project should use Object-Oriented Programming principles, incorporate features like inheritance, polymorphism, templates, and smart pointers, and ensure data persistence using JSON.

## Core Features:
### Books Management:

1. Add, update, and remove books.
2. Search for books by title, author, or ISBN.
3. View a list of all available books.

## Member Management:
1. Register new members.
2. Update or remove member information.
3. Search for members by name or membership ID.

## Borrowing Transactions:
1. Borrow a book (only if available).
2. Return a borrowed book.
3. View borrowing history for each member.
4. Prevent a member from borrowing more than a certain number of books.

## Data Persistence:
1. Store all data (books, members, and transactions) in JSON files.
2. Load data from files at startup and save data when exiting.

# Advanced Features:

## Book Categories:
1. Different categories of books (e.g., Fiction, Non-fiction, Science, History).
2. Use inheritance to represent different types of books.

## Member Types:
1. Different types of memberships (e.g., Regular, Premium).
2. Use inheritance to represent different member types with varying privileges (e.g., borrowing limits).

## Template Programming:
1. Use templates to handle common operations across different types of collections (e.g., searching, sorting).

## Smart Pointers:
1. Use std::shared_ptr for managing shared resources like books and members.
2. Use std::unique_ptr where appropriate for unique ownership (e.g., transactions).

## Polymorphism:
1. Use polymorphism for handling different types of books and members, ensuring the correct behavior for each type.

## Unit Testing:
1. Write unit tests using a testing framework like Google Test (gtest) to ensure the correctness of core functionalities.

## Project Structure ::

```
LibraryManagementSystem/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── Book.cpp
│   ├── Member.cpp
│   ├── Transaction.cpp
│   ├── Library.cpp
├── include/
│   ├── Book.h
│   ├── Member.h
│   ├── Transaction.h
│   ├── Library.h
├── data/
│   ├── books.json
│   ├── members.json
│   ├── transactions.json
├── tests/
│   ├── BookTest.cpp
│   ├── MemberTest.cpp
│   ├── TransactionTest.cpp
│   ├── LibraryTest.cpp
├── third_party/
│   ├── json.hpp
└── README.md
```
