cmake_minimum_required(VERSION 4.1)
project(ejemploUsoOpConClases)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejemploUsoOpConClases main.cpp
        Biblioteca/Vehiculo.cpp
        Biblioteca/Vehiculo.h
        Biblioteca/Sistema.cpp
        Biblioteca/Sistema.h
        Biblioteca/Accesorio.cpp
        Biblioteca/Accesorio.h)
