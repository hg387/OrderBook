#pragma once
#include "book.h"
#include <string>

namespace Parser{
    void on_market_data(char const* data) noexcept;

    TopOfBook get_top_of_book(const std::string& symbol) noexcept;
}