set( PROBLEM_SOURCES
    problem_006.cpp )

add_executable( problem_006
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_006
    projectEuler_lib )
