set( PROBLEM_SOURCES
    problem_009.cpp )

add_executable( problem_009
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_009
    projectEuler_lib )
