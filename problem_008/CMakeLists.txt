set( PROBLEM_SOURCES
    problem_008.cpp )

add_executable( problem_008
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_008
    projectEuler_lib )
