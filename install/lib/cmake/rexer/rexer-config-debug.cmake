#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rexer" for configuration "Debug"
set_property(TARGET rexer APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(rexer PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/librexer.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/librexer.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS rexer )
list(APPEND _IMPORT_CHECK_FILES_FOR_rexer "${_IMPORT_PREFIX}/lib/librexer.dll.a" "${_IMPORT_PREFIX}/bin/librexer.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
