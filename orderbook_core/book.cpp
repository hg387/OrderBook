#include "book.h"

Book* Book::instance = nullptr;
std::once_flag Book::initInstanceFlag;
std::unordered_map<std::string, std::shared_ptr<TopOfBook>> Book::snapshots{}; 

void Book::initBook(){
    instance = new Book();
}

Book* Book::getInstance(){
    std::call_once(initInstanceFlag, initBook);
    return instance;
}

void Book::addOrder(std::string symbol, int bid_price, int bid_quantity, int ask_price, int ask_quantity){
    std::shared_ptr<TopOfBook> top_of_book;
    if (snapshots.find(symbol) == snapshots.end()){
        snapshots[symbol] = std::make_shared<TopOfBook>(symbol);
    }
    
    top_of_book = snapshots[symbol];
    (*top_of_book).addOrder<Order::BUY>(bid_quantity, bid_price);
    (*top_of_book).addOrder<Order::SELL>(ask_quantity, ask_price);
    snapshots[symbol] = top_of_book;
}

