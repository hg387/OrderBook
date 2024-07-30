#include "book.h"

Book* Book::instance = nullptr;
std::once_flag Book::initInstanceFlag;
std::unordered_map<std::string, TopOfBook*> Book::snapshots{}; 

void Book::initBook(){
    instance = new Book();
}

Book* Book::getInstance(){
    std::call_once(initInstanceFlag, initBook);
    return instance;
}