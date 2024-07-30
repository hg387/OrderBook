#pragma once
#include "top_of_book.h"
#include <string>

namespace Parser{
    void on_market_data(char const* data);

    TopOfBook get_top_of_book(const std::string& symbol);
}