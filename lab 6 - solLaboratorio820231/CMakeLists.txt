cmake_minimum_required(VERSION 4.2)
project(SolLaboratorio820231)

set(CMAKE_CXX_STANDARD 20)

add_executable(SolLaboratorio820231 main.cpp
        Biblioteca/Alumno.cpp
        Biblioteca/Alumno.h
        Biblioteca/Escala.cpp
        Biblioteca/Escala.h
        Biblioteca/Presencial.cpp
        Biblioteca/Presencial.h
        Biblioteca/Semipresencial.cpp
        Biblioteca/Semipresencial.h
        Biblioteca/Virtual.cpp
        Biblioteca/Virtual.h
        Biblioteca/Tesoreria.cpp
        Biblioteca/Tesoreria.h)
