file(GLOB_RECURSE C_FILES ./*.c)

add_library(csys SHARED ${C_FILES})

add_executable(test_malloc test_malloc.c)
target_link_libraries(test_malloc csys)