cmake_minimum_required(VERSION 3.2)
project(projectEuler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    problem_001/problem_001.cpp
    # problem_002/problem_002.cpp
    # problem_003/problem_003.cpp
    # problem_004/problem_004.cpp
    # problem_005/problem_005.cpp
    # problem_006/problem_006.cpp
    # problem_007/problem_007.cpp
    # problem_008/problem_008.cpp
    # problem_009/problem_009.cpp
    # problem_010/problem_010.cpp
    # problem_011/problem_011.cpp
    # problem_014/problem_014.cpp
    # problem_048/problem_048.cpp
    # problem_050/problem_050.cpp
    # problem_076/problem_076.cpp
    # problem_099/problem_099.cpp
    # problem_102/problem_102.cpp
    )

# add_executable(projectEuler ${SOURCE_FILES} libsrc/projectEuler_math.cpp libsrc/projectEuler_math.h)
add_executable(projectEuler_problem_001 problem_001/problem_001.cpp libsrc/projectEuler_math.cpp libsrc/projectEuler_math.h)
add_executable(projectEuler_problem_002 problem_002/problem_002.cpp libsrc/projectEuler_math.cpp libsrc/projectEuler_math.h)
