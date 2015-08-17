set( LIBRARY_SOURCES projectEuler_math.cpp )

set( LIBRARY_HEADERS projectEuler_math.h )

# Build the library
add_library( projectEuler_lib ${LIBRARY_SOURCES} )

# Install the library
install( TARGETS projectEuler_lib
    DESTINATION ${projectEuler_SOURCE_DIR}/lib )

# Install the header files
install( FILES ${LIBRARY_HEADERS}
    DESTINATION ${projectEuler_SOURCE_DIR}/includes )
