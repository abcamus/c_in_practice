# add_executable(run_alg recursive.c)
set(LEETCODE_DIRS
    hashmap
    binary_search)

set(LEETCODE_SRC_FILES)
foreach(DIR ${LEETCODE_DIRS})
    AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/${DIR} SUB_ALG_SRC)
    list(APPEND LEETCODE_SRC_FILES ${SUB_ALG_SRC})
endforeach()

add_library(leetcode ${LEETCODE_SRC_FILES})

target_include_directories(leetcode PRIVATE ./)