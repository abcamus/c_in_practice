file(GLOB_RECURSE C_FILES ./*.c)

add_executable(demo_prim ${C_FILES})
target_link_libraries(demo_prim pthread)