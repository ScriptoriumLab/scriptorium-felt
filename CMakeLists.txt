cmake_minimum_required(VERSION 3.25)
project(modian-common)

set(CMAKE_CXX_STANDARD 23)

include(CTest)

add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
