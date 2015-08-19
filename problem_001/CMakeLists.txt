set( PROBLEM_SOURCES problem_001.cpp )

add_executable( problem_001 ${PROBLEM_SOURCES} )

target_link_libraries( problem_001 projectEuler_lib )

install( TARGETS problem_001 DESTINATION ${projectEuler_SOURCE_DIR}/bin )
