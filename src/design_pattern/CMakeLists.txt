file(GLOB_RECURSE SRC_FILES *.c)

add_executable(demo_dp ${SRC_FILES})
target_include_directories(demo_dp PRIVATE inc)