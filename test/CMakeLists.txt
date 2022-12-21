cmake_minimum_required(VERSION 3.5)

AUX_SOURCE_DIRECTORY(cases SRC_CASES)

set(SRC 
    main.cc
    ${SRC_CASES})

add_executable(test_main ${SRC})
target_include_directories(test_main PRIVATE include)
target_link_libraries(test_main ${PROJECT_SOURCE_DIR}/lib/libgtest.a)