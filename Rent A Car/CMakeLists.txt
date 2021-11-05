cmake_minimum_required(VERSION 3.20)
project(Rent_A_Car)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

set(SFML_INCLUDE_DIR "SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "SFML-2.5.1/lib")
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML-2.5.1 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Rent_A_Car main.cpp Graph.cpp Graph.h Interfaz/Ventana.cpp Interfaz/Ventana.h Interfaz/Calle.cpp Interfaz/Calle.h Interfaz/Ciudad.cpp Interfaz/Ciudad.h)
target_link_libraries(Rent_A_Car sfml-graphics sfml-window sfml-system)