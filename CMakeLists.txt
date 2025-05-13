cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ProjectEuler)

set(CMAKE_INSTALL_BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_INSTALL_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_INSTALL_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# set the CXXFLAGS to -o3 -g -ggdb -Wall
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g -ggdb -Wall")

# Add the include directory
include_directories(libsrc)
add_subdirectory(libsrc)

message(STATUS "from libsrc LIBRARY_LIST: ${LIBRARY_LIST}")
set(LIBRARY_LIST "utils")
message(STATUS "from root LIBRARY_LIST: ${LIBRARY_LIST}")

# Find the src/utils directory
file(GLOB_RECURSE
    FOLDER_LIST
    LIST_DIRECTORIES true
    "src/utils")
if (FOLDER_LIST)
    message(STATUS "Found folder list: ${FOLDER_LIST}")
    foreach(folder ${FOLDER_LIST})
        if (IS_DIRECTORY ${folder})
            get_filename_component(folder_name ${folder} NAME)
            message(STATUS "Found folder: ${folder}")

                file(GLOB_RECURSE SOURCES "${folder}/*.cpp")
                # Check if SOURCES is not empty
                if (SOURCES)
                    message(STATUS "Adding executable for folder: ${folder_name}")

                    # Add the executable and install targets for the current folder
                    add_executable(${folder_name} ${SOURCES})
                    target_link_libraries(${folder_name} ${LIBRARY_LIST})

                    install(TARGETS ${folder_name} RUNTIME DESTINATION ${CMAKE_INSTALL_BIN_DIR})
                    
                    # Check for additional data files in the current folder
                    file(GLOB_RECURSE DATA_FILES "src/${folder_name}/*.txt")
                    if (DATA_FILES)
                        message(STATUS "Installing data files for folder: ${folder_name}")
                        install(FILES ${DATA_FILES} DESTINATION ${CMAKE_INSTALL_BIN_DIR})
                    else()
                        message(STATUS "No data files found in folder: src/${folder_name}")
                    endif(DATA_FILES)

                else()
                    message(STATUS "No source files found in folder: src/${folder_name}")
                endif(SOURCES)


        endif()
    endforeach(folder)
else()
    message(STATUS "No folders found")
endif(FOLDER_LIST)

# Add a clean targets to remove all bin, lib, and include
add_custom_target(clean-install-dir
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_BIN_DIR}
    COMMENT "Cleaning all executables and data files"
)
add_custom_target(clean-lib-dir
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_LIB_DIR}
    COMMENT "Cleaning all libraries"
)
add_custom_target(clean-inc-dir
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_INC_DIR}
    COMMENT "Cleaning all header files"
)
add_custom_target(clean-all
    DEPENDS clean-install-dir clean-lib-dir clean-inc-dir
    COMMAND ${CMAKE_COMMAND} -E echo "Cleaned all directories"
    COMMENT "Cleaning all directories"
)