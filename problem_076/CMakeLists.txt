set( PROBLEM_SOURCES
    problem_076.cpp )

add_executable( problem_076
    ${PROBLEM_SOURCES} )

target_link_libraries( problem_076
    projectEuler_lib )

install( TARGETS problem_076
    DESTINATION ${projectEuler_SOURCE_DIR}/bin )
