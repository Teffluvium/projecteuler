cmake_minimum_required(VERSION 3.2)
project(projectEuler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# file( MAKE_DIRECTORY ${projectEuler_SOURCE_DIR}/bin )
# file( MAKE_DIRECTORY ${projectEuler_SOURCE_DIR}/includes )
# file( MAKE_DIRECTORY ${projectEuler_SOURCE_DIR}/lib )

add_subdirectory( libsrc )
include_directories( ${PROJECT_SOURCE_DIR}/libsrc )

add_subdirectory( problem_001 )
add_subdirectory( problem_002 )
add_subdirectory( problem_003 )
add_subdirectory( problem_004 )
add_subdirectory( problem_005 )
add_subdirectory( problem_006 )
add_subdirectory( problem_007 )
add_subdirectory( problem_008 )
add_subdirectory( problem_009 )
add_subdirectory( problem_010 )
add_subdirectory( problem_011 )
add_subdirectory( problem_014 )
add_subdirectory( problem_048 )
add_subdirectory( problem_050 )
add_subdirectory( problem_076 )
add_subdirectory( problem_099 )

enable_testing()
add_test( test_problem_001 ${projectEuler_SOURCE_DIR}/bin/problem_001 )
add_test( test_problem_002 ${projectEuler_SOURCE_DIR}/bin/problem_002 )

add_test( test_problem_001_strcmp ${projectEuler_SOURCE_DIR}/bin/problem_001 )
set_tests_properties( test_problem_001_strcmp
    PROPERTIES PASS_REGULAR_EXPRESSION "233168" )
