file(GLOB_RECURSE C_FILES ./*.c)

add_library(csys SHARED ${C_FILES})

add_executable(demo_malloc test_malloc.c)
target_link_libraries(demo_malloc csys)
