file(GLOB_RECURSE C_FILES ./*.c)

add_library(csys SHARED ${C_FILES})