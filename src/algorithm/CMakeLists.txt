# add_executable(run_alg recursive.c)
set(ALG_TYPE_DIRS
    hashmap
    binary_search)

set(ALG_SRC_FILES)
foreach(DIR ${ALG_TYPE_DIRS})
    AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/leetcode/${DIR} SUB_ALG_SRC)
    list(APPEND ALG_SRC_FILES ${SUB_ALG_SRC})
endforeach()

add_library(alg ${ALG_SRC_FILES})

target_include_directories(alg INTERFACE leetcode)