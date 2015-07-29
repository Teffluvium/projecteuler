set( PROBLEM_SOURCES
    problem_010.cpp )

add_executable( problem_010
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_010
    projectEuler_lib )
