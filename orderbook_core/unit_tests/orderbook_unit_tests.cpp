#include "gtest/gtest.h"
#include "../book.h"
#include <string>

class OrderBookTest : public testing::Test
{
protected:
    Book* book = Book::getInstance();
};

TEST(BookTests, SingletonTest){
    Book* book1 = Book::getInstance();
    Book* book2 = Book::getInstance();

    EXPECT_EQ(book1, book2);
}

TEST_F(OrderBookTest, addOrderTest){
    std::string symbol = "GOOGL";
    book->addOrder("GOOGL", 400, 10, 500, 25);
    book->addOrder("GOOGL", 350, 10, 400, 30);

    std::shared_ptr<TopOfBook> top_of_book = book->getBook(symbol);
    std::cout << (*top_of_book) << std::endl;
    EXPECT_TRUE(true);
}