include(GNUInstallDirs)

function(target_public_headers TARGET INCLUDES INSTALL_INCLUDES)
    message(STATUS "ASDF ${TARGET} ${INCLUDES} ${INSTALL_INCLUDES}")

    get_target_property(rexer PROPERTIES PUBLIC_HEADER)

    foreach (header ${ARGN})
        file(RELATIVE_PATH header_file_path "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/${INCLUDES}" "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/${INCLUDES}/${header}")
        message(STATUS ${header_file_path})
#        get_filename_component(header_directory_path "${header_file_path}" DIRECTORY)
#        set_target_properties(${TARGET} PROPERTIES
#            PUBLIC_HEADER ${INSTALL_INCLUDES}/${header_directory_path})
    endforeach ()
endfunction()
