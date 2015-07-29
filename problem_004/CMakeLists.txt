set( PROBLEM_SOURCES
    problem_004.cpp )

add_executable( problem_004
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_004
    projectEuler_lib )
