cmake_minimum_required(VERSION 3.25)
project(scriptorium-felt)

set(CMAKE_CXX_STANDARD 23)

include(CTest)

add_subdirectory(core)
add_subdirectory(infra)
add_subdirectory(service)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
