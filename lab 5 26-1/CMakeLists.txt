cmake_minimum_required(VERSION 4.0)
project(lab_26_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_26_1 main.cpp
        Bibliotecas/Mascota.cpp
        Bibliotecas/Mascota.h
        Bibliotecas/VacunaAplicada.cpp
        Bibliotecas/VacunaAplicada.h
        Bibliotecas/Veterinaria.cpp
        Bibliotecas/Veterinaria.h)
