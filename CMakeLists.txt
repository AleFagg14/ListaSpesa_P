cmake_minimum_required(VERSION 3.27)
project(ListaSpesa_P)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListaSpesa_P main.cpp
        Item.h
        Item.cpp
        Observer.h
        ShoppingList.cpp
        User.cpp)

