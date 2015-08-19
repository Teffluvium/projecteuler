set( PROBLEM_SOURCES problem_102.cpp )

add_executable( problem_102 ${PROBLEM_SOURCES} )

target_link_libraries( problem_102 projectEuler_lib )

install( TARGETS problem_102 DESTINATION ${projectEuler_SOURCE_DIR}/bin )
install( FILES problem_102.triangles.txt
    DESTINATION ${projectEuler_SOURCE_DIR}/resources )
