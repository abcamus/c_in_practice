cmake_minimum_required(VERSION 3.10)

project(realworld_c)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE debug CACHE STRING "Build Type" FORCE)
endif()

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Debug Configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "Release Configuration: ${CMAKE_CXX_FLAGS_RELEASE}")

# set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -O2")

add_subdirectory(src)
add_subdirectory(test)