#include "gtest/gtest.h"
#include "../book.h"
#include "../parser.h"
#include <string>
#include <sstream>

class OrderBookTest : public testing::Test
{
protected:
    Book *book = Book::getInstance();
};

TEST(BookTests, SingletonTest)
{
    Book *book1 = Book::getInstance();
    Book *book2 = Book::getInstance();

    EXPECT_EQ(book1, book2);
}

TEST(ParserTest, ParserMarketDataTest)
{
    const char *data = "META 455 501 10 25";
    Parser::on_market_data(data);

    std::string symbol = "META";
    TopOfBook top_of_book = Parser::get_top_of_book(symbol);
    EXPECT_EQ(10, top_of_book.buyQuantities[455]->quantity);
    EXPECT_EQ(25, top_of_book.sellQuantities[501]->quantity);
}

TEST(ParserTest, ParserMarketDataMultipleTest)
{
    const char *data1 = "META 430 497 10 25";
    const char *data2 = "META 500 460 2 15";
    const char *data3 = "META 500 460 2 15";

    Parser::on_market_data(data1);
    Parser::on_market_data(data2);
    Parser::on_market_data(data3);

    std::string symbol = "META";
    TopOfBook top_of_book = Parser::get_top_of_book(symbol);
    EXPECT_EQ(4, top_of_book.buyQuantities[500]->quantity);
    EXPECT_EQ(30, top_of_book.sellQuantities[460]->quantity);
}

TEST_F(OrderBookTest, InitTest)
{
    std::string symbol = "APPL";
    std::stringstream ss;
    book->addOrder("APPL", 400, 10, 500, 25);

    std::shared_ptr<TopOfBook> top_of_book = book->getBook(symbol);
    ss << (*top_of_book);

    std::string expected_book = "\n----------------------- BUY -----------------------\n"
                                "Qty: 10 Price: 400\n"
                                "***************************************************\n"
                                "\n----------------------- SELL ----------------------\n"
                                "Qty: 25 Price: 500\n"
                                "***************************************************\n";
    EXPECT_EQ(expected_book, ss.str());
}

TEST_F(OrderBookTest, addMultiOrderTest)
{
    std::string symbol = "GOOGL";
    book->addOrder("GOOGL", 400, 10, 500, 25);
    book->addOrder("GOOGL", 350, 5, 400, 30);

    std::shared_ptr<TopOfBook> top_of_book = book->getBook(symbol);
    EXPECT_EQ(10, top_of_book->buyQuantities[400]->quantity);
    EXPECT_EQ(30, top_of_book->sellQuantities[400]->quantity);
}

TEST_F(OrderBookTest, addDuplicatePricesOrderTest)
{
    std::string symbol = "O";
    book->addOrder("O", 400, 10, 500, 25);
    book->addOrder("O", 400, 15, 400, 30);
    book->addOrder("O", 300, 11, 400, 15);

    std::shared_ptr<TopOfBook> top_of_book = book->getBook(symbol);
    EXPECT_EQ(25, top_of_book->buyQuantities[400]->quantity);
    EXPECT_EQ(45, top_of_book->sellQuantities[400]->quantity);
}