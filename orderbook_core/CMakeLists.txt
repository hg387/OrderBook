find_package(Threads REQUIRED)
add_library(orderbook_core parser.cpp parser.h order.h book.cpp book.h top_of_book.cpp top_of_book.h)

target_compile_features(orderbook_core PUBLIC cxx_std_20)
target_link_libraries(orderbook_core PUBLIC Threads::Threads)