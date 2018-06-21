cmake_minimum_required(VERSION 2.8)
project(example)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-O3 -pthread -std=c++14 -pedantic")
set(CMAKE_CXX_STANDARD 14)
set(MecaCellDir ~/MecaCell)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

file(GLOB SRC
	"src/scenario.hpp"
	"src/cell.hpp"
	)

link_directories(${MecaCellDir}/build/mecacell)
link_directories(${MecaCellDir}/build/mecacellviewer)
include_directories(${MecaCellDir})

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Quick)
find_package(Qt5OpenGL)
add_executable(example ${SRC} src/example.cpp)
target_link_libraries(example mecacell mecacellviewer Qt5::Quick Qt5::Core Qt5::Gui OpenGL)
