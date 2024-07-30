cmake_minimum_required(VERSION 3.5.0)
project(tradebook VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(orderbook_core)
add_subdirectory(orderbook_core/unit_tests)

add_executable(tradebook orderbook.m.cpp)
target_link_libraries(tradebook PUBLIC orderbook_core)

include(CTest)
enable_testing()

target_compile_features(tradebook PUBLIC cxx_std_20)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
