find_package(JlCxx REQUIRED)

add_library(hello SHARED hello.cpp)
target_link_libraries(hello JlCxx::cxxwrap_julia)

add_library(parametric SHARED parametric.cpp)
target_link_libraries(parametric JlCxx::cxxwrap_julia)
