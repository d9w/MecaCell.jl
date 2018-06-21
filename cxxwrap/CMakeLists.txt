find_package(JlCxx REQUIRED)

add_library(hello SHARED hello.cpp)
target_link_libraries(hello JlCxx::cxxwrap_julia)
