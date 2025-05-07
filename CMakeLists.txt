cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ProjectEuler)

set(CMAKE_INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Loop through folders in the src directory and print their names
file(GLOB_RECURSE FOLDERS LIST_DIRECTORIES true "src/*")
foreach(folder ${FOLDERS})
    if(IS_DIRECTORY ${folder})
        get_filename_component(folder_name ${folder} NAME)
        message(STATUS "Found folder: src/${folder_name}")
        file(GLOB_RECURSE SOURCES "src/${folder_name}/*.cpp")
        # Check if SOURCES is not empty
        if(SOURCES)
            message(STATUS "Adding executable for folder: ${folder_name}")

            # Add the executable and install targets for the current folder
            add_executable(${folder_name} ${SOURCES})
            install(TARGETS ${folder_name} RUNTIME DESTINATION ${CMAKE_INSTALL_DIR})
            
            # Check for additional data files in the current folder
            file(GLOB_RECURSE DATA_FILES "src/${folder_name}/*.txt")
            if(DATA_FILES)
                message(STATUS "Installing data files for folder: ${folder_name}")
                install(FILES ${DATA_FILES} DESTINATION ${CMAKE_INSTALL_DIR})
            else()
                message(STATUS "No data files found in folder: src/${folder_name}")
            endif(DATA_FILES)

        else()
            message(STATUS "No source files found in folder: src/${folder_name}")
        endif(SOURCES)
    endif()
endforeach(folder)

# Add a clean target to remove all executables and data files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_DIR}
    COMMENT "Cleaning all executables and data files"
)