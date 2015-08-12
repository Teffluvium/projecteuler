set( PROBLEM_SOURCES
    problem_050.cpp )

add_executable( problem_050
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_050
    projectEuler_lib )
