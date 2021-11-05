cmake_minimum_required(VERSION 3.20)
project(Rent_A_Car)

set(CMAKE_CXX_STANDARD 14)

add_executable(Rent_A_Car main.cpp Graph.cpp Graph.h Interfaz/Ventana.cpp Interfaz/Ventana.h Interfaz/Calle.cpp Interfaz/Calle.h Interfaz/Ciudad.cpp Interfaz/Ciudad.h)
