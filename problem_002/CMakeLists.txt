set( PROBLEM_SOURCES
    problem_002.cpp )

add_executable( problem_002
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_002
    projectEuler_lib )
