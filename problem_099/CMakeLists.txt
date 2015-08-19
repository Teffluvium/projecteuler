set( PROBLEM_SOURCES problem_099.cpp )

add_executable( problem_099 ${PROBLEM_SOURCES} )

target_link_libraries( problem_099 projectEuler_lib )

install( TARGETS problem_099 DESTINATION ${projectEuler_SOURCE_DIR}/bin )
install( FILES problem_099.base_exp.txt DESTINATION
    ${projectEuler_SOURCE_DIR}/resources )
