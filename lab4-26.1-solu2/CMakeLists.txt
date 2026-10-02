cmake_minimum_required(VERSION 3.20)
project(ListaGenerica)

set(CMAKE_CXX_STANDARD 17)

add_executable(ListaGenerica main.cpp
        Biblioteca/BibliotecaGenerica.cpp
        Biblioteca/BibliotecaEnteros.cpp
        Biblioteca/BibliotecaRegistros.cpp)

# CLion ejecuta desde cmake-build-debug: se copian ahí las carpetas de archivos.
file(COPY ${CMAKE_SOURCE_DIR}/ArchivosIngreso DESTINATION ${CMAKE_BINARY_DIR})
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/ArchivosSalida)
