#include "Transaction.h"
#include <memory>

Transaction::Transaction(std::shared_ptr<Member> member, std::shared_ptr<Book> book, const std::time_t& date,
                    bool isBorrowing) : member(member), book(book), date(date), borrowing(isBorrowing) {}
        
std::shared_ptr<Member> Transaction::getMember() const{
    return member;
}
std::shared_ptr<Book> Transaction::getBook() const{
    return book;
}
std::time_t Transaction::getDate() const{
    return date;
}
bool Transaction::isBorrowing() const{
    return borrowing;
}
