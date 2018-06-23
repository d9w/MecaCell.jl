cmake_minimum_required(VERSION 3.1)
project(example)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-O3 -pthread -std=c++14 -pedantic")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(MECACELL_DIR include/mecacell)

file(GLOB SRC
	"mecaexample/*.hpp"
)

add_executable(console ${SRC} mecaexample/console.cpp)
target_include_directories(console PUBLIC ${MECACELL_DIR})

set(MECACELL_VIEWER_DIR ${MECACELL_DIR}/mecacellviewer)
find_package(Qt5 COMPONENTS Core Quick REQUIRED)
set(CMAKE_AUTOMOC ON)
cmake_policy(SET CMP0071 NEW)
qt5_wrap_cpp(MOC_SRC ${MECACELL_VIEWER_DIR}/signalslotbase.h ${MECACELL_VIEWER_DIR}/camera.hpp)
qt5_add_resources(RESOURCES ${MECACELL_VIEWER_DIR}/resourcesLibMecacellViewer.qrc)
add_executable(viewer ${SRC} ${MOC_SRC} ${RESOURCES} mecaexample/viewer.cpp)
target_link_libraries(viewer Qt5::Core Qt5::Quick)
target_include_directories(viewer PUBLIC ${MECACELL_DIR} ${MECACELL_VIEWER_DIR})
