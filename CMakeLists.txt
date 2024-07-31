cmake_minimum_required(VERSION 3.5.0)
project(orderbook VERSION 0.1.0 LANGUAGES C CXX)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_subdirectory(orderbook_core)
add_subdirectory(orderbook_core/unit_tests)

add_executable(orderbook orderbook.m.cpp)
target_link_libraries(orderbook PUBLIC orderbook_core)

include(CTest)
enable_testing()

target_compile_features(orderbook PUBLIC cxx_std_20)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
