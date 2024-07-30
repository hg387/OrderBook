add_library(orderbook_core parser.cpp parser.h top_of_book.cpp top_of_book.h)

target_compile_features(orderbook_core PUBLIC cxx_std_20)