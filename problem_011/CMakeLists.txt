set( PROBLEM_SOURCES
    problem_011.cpp )

add_executable( problem_011
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_011
    projectEuler_lib )
