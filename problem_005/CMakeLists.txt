set( PROBLEM_SOURCES
    problem_005.cpp )

add_executable( problem_005
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_005
    projectEuler_lib )
