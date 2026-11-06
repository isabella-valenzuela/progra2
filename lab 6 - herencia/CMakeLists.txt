cmake_minimum_required(VERSION 4.2)
project(Herencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(Herencia main.cpp
        Biblioteca/Perro.cpp
        Biblioteca/Perro.h
        Biblioteca/Gato.cpp
        Biblioteca/Gato.h
        Biblioteca/Animal.cpp
        Biblioteca/Animal.h)
