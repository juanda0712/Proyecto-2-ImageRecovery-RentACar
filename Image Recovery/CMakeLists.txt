cmake_minimum_required(VERSION 3.20)
project(Image_Recovery)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/qt5")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Image_Recovery main.cpp App.cpp App.h genetic_algorithm/Genetics.cpp genetic_algorithm/Genetics.h genetic_algorithm/Individual.cpp genetic_algorithm/Individual.h genetic_algorithm/Population.cpp genetic_algorithm/Population.h ImageOperations.cpp ImageOperations.h)
target_link_libraries(Image_Recovery
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${OpenCV_LIBS}
        )

