cmake_minimum_required(VERSION 3.20)
project(Image_Recovery)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Image_Recovery main.cpp)
target_link_libraries(Image_Recovery
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
