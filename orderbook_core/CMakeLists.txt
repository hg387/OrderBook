add_library(orderbook_core parser.cpp parser.h book.cpp book.h)

target_compile_features(orderbook_core PUBLIC cxx_std_20)