#include "parser.h"
#include "book.h"
#include <sstream>
#include <string>
#include <iostream>

void Parser::on_market_data(char const *data) noexcept
{
    std::stringstream ss;
    ss << data;

    std::string symbol{};
    size_t prices[2];
    size_t sizes[2];

    for (int i = 0; i != 5; ++i)
    {
        if (i == 0)
            ss >> symbol;
        else if (i == 1 || i == 2)
            ss >> prices[i - 1];
        else
            ss >> sizes[i - 3];

        if (ss.fail())
        {
            std::cout << "Error processing market data" << std::endl;
            ss.clear();
            return;
        }
    }

    Book *book = Book::getInstance();
    book->addOrder(symbol, prices[0], sizes[0], prices[1], sizes[1]);
};

TopOfBook Parser::get_top_of_book(const std::string &symbol) noexcept
{
    Book *book = Book::getInstance();
    std::shared_ptr<TopOfBook> top_of_book = book->getBook(symbol);

    if (top_of_book.get() != nullptr)
        return *top_of_book;
    return TopOfBook{""};
};

void Parser::printCompleteBook() noexcept
{
    Book::getInstance()->printBook();
}