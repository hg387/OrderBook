#pragma once
#include <mutex>
#include "top_of_book.h"

class Book{
    private:
        static std::once_flag initInstanceFlag;
        static Book* instance;
        static std::unordered_map<std::string, std::shared_ptr<TopOfBook>> snapshots; 

        Book() = default;
        ~Book() = default;

        static void initBook();

    public:
        Book(const Book&) = delete;
        Book& operator=(const Book&) = delete;

        static Book* getInstance();
        void addOrder(std::string symbol, int bid_price, int bid_quantity, int ask_price, int ask_quantity);
};
