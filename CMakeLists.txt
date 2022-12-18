cmake_minimum_required(VERSION 3.10)

project(realworld_c)

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++11 -O2")

add_subdirectory(src)