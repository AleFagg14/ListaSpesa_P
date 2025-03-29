cmake_minimum_required(VERSION 3.27)
project(ListaSpesa_P)

set(CMAKE_CXX_STANDARD 17)

# Aggiungi Google Test come dipendenza
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Aggiungi l'eseguibile principale
add_executable(ListaSpesa_P main.cpp
        Item.h
        Item.cpp
        Observer.h
        ShoppingList.cpp
        User.cpp)

# Aggiungi l'eseguibile per i test
add_executable(tests
        test.cpp  # File con i tuoi test
)

# Linka Google Test all'eseguibile dei test
target_link_libraries(tests GTest::gtest_main)

# Registra il test con CMake
add_test(NAME TestListaSpesa COMMAND tests)


