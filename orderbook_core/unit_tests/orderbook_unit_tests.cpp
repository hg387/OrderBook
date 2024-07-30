#include "gtest/gtest.h"
#include "../book.h"

TEST(BookTests, SingletonTest){
    Book* book1 = Book::getInstance();
    Book* book2 = Book::getInstance();

    EXPECT_EQ(book1, book2);
}