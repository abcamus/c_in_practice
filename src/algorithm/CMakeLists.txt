add_subdirectory(leetcode)

set(ALG_SRC_FILES
    recursive.cc
    k_mins.cc)
add_library(alg ${ALG_SRC_FILES})
target_link_libraries(alg leetcode)
target_include_directories(alg INTERFACE leetcode)