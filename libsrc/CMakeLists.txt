# CMakeLists.txt for the libraries
set(LIBRARY_LIST "utils")

set(SOURCES "utils.cpp")

set(HEADERS "utils.h")

# Build the utils library
add_library(utils ${SOURCES})
install(TARGETS utils DESTINATION ${CMAKE_INSTALL_LIB_DIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INC_DIR})
