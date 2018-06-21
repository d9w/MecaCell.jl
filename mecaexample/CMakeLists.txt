file(GLOB SRC
	"scenario.hpp"
	"cell.hpp"
	)

link_directories(${MecaCellDir}/build/mecacell)
link_directories(${MecaCellDir}/build/mecacellviewer)
include_directories(${MecaCellDir})

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Quick)
find_package(Qt5OpenGL)
add_executable(example ${SRC} example.cpp)
target_link_libraries(example mecacell mecacellviewer Qt5::Quick Qt5::Core Qt5::Gui OpenGL)
