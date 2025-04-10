cmake_minimum_required(VERSION 3.27)
project(ListaSpesa_P)

set(CMAKE_CXX_STANDARD 17)

# === Google Test Setup ===
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# === Shared Library ===
add_library(ShoppingLib
        Item.cpp
        ShoppingList.cpp
        User.cpp
)

target_include_directories(ShoppingLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# === Main Executable ===
add_executable(ListaSpesa_P main.cpp)
target_link_libraries(ListaSpesa_P PRIVATE ShoppingLib)

# === Tests Executable ===
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE ShoppingLib GTest::gtest)

# Mark it as a Google Test for CLion
set_target_properties(tests PROPERTIES LABELS "gtest")

# === Enable Tests ===
enable_testing()
add_test(NAME TestListaSpesa COMMAND tests)
