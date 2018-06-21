# Hello world example, similar to the Boost.Python hello world

using CxxWrap
using Base.Test

# Wrap the functions defined in C++
wrap_modules("build/cxxwrap/libhello")

# Output:
Hello.hello()
