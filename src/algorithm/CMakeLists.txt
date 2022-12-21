# add_executable(run_alg recursive.c)
AUX_SOURCE_DIRECTORY(leetcode ALG_SRC)
add_library(alg ${ALG_SRC})

target_include_directories(alg INTERFACE leetcode)