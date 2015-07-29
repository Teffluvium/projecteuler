set( PROBLEM_SOURCES
    problem_007.cpp )

add_executable( problem_007
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_007
    projectEuler_lib )
