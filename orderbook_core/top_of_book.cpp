#include "top_of_book.h"

TopOfBook* TopOfBook::instance = nullptr;
std::once_flag TopOfBook::initInstanceFlag;

void TopOfBook::initTopOfBook(){
    instance = new TopOfBook();
}

TopOfBook* TopOfBook::getInstance(){
    std::call_once(initInstanceFlag, initTopOfBook);
    return instance;
}