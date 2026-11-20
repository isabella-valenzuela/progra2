cmake_minimum_required(VERSION 4.4)
project(lab9_25_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab9_25_2 main.cpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.h
        Bibliotecas/Vehiculo.cpp
        Bibliotecas/Vehiculo.h
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.h
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.h
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.h)
