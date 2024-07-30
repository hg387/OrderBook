include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(orderbook_unit_tests orderbook_unit_tests.cpp)
target_link_libraries(orderbook_unit_tests PUBLIC orderbook_core GTest::gtest_main )
target_compile_features(orderbook_unit_tests PUBLIC cxx_std_20)
include(GoogleTest)
gtest_add_tests(TARGET orderbook_unit_tests)
