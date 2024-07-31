#include "book.h"
#include <iostream>

Book *Book::instance = nullptr;
std::once_flag Book::initInstanceFlag;
std::unordered_map<std::string, std::shared_ptr<TopOfBook>> Book::snapshots{};

void Book::initBook() noexcept
{
    instance = new Book();
}

Book *Book::getInstance() noexcept
{
    std::call_once(initInstanceFlag, initBook);
    return instance;
}

void Book::addOrder(std::string symbol, int bid_price, int bid_quantity, int ask_price, int ask_quantity) noexcept
{
    std::shared_ptr<TopOfBook> top_of_book;
    if (snapshots.find(symbol) == snapshots.end())
    {
        snapshots[symbol] = std::make_shared<TopOfBook>(symbol);
    }

    top_of_book = snapshots[symbol];
    (*top_of_book).addOrder<Order::BUY>(bid_quantity, bid_price);
    (*top_of_book).addOrder<Order::SELL>(ask_quantity, ask_price);
    snapshots[symbol] = top_of_book;
}

std::shared_ptr<TopOfBook> Book::getBook(const std::string &symbol) noexcept
{
    if (snapshots.find(symbol) != snapshots.end())
        return snapshots[symbol];

    std::cout << "Error symbol " << symbol << " not found!" << std::endl;
    return std::shared_ptr<TopOfBook>{};
}

void Book::printBook() noexcept
{
    for (const auto &sym : snapshots)
    {
        std::cout << "\n----------------------- " << sym.first << " -----------------------" << std::endl;
        std::cout << (*sym.second) << std::endl;
        std::cout << "----------------------- " << sym.first << " -----------------------\n"
                  << std::endl;
    }
}
