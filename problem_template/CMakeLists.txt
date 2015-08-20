# List source code files
set( PROBLEM_SOURCES problem_template.cpp )

# List header files
#set( PROBLEM_HEADERS problem_template.h )

# List additional resource files
#set( PROBLEM_RESOURCES problem_template.resource.txt )

## Compile and link
# Compile the executable
add_executable( problem_template ${PROBLEM_SOURCES} )
# Add library dependencies
target_link_libraries( problem_template projectEuler_lib )

## Installers
# Install executable
install(
    TARGETS     problem_template
    DESTINATION ${projectEuler_SOURCE_DIR}/bin )
# Install headers
install(
    FILES       ${PROBLEM_HEADERS}
    DESTINATION ${projectEuler_SOURCE_DIR}/includes )
# Install resources
install(
    FILES       ${PROBLEM_RESOURCES}
    DESTINATION ${projectEuler_SOURCE_DIR}/resources )
