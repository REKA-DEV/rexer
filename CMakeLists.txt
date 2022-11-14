cmake_minimum_required(VERSION 3.0)
project(rexer)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install CACHE PATH "install here" FORCE)

add_subdirectory(src)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING
        PATTERN *.h)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}-export
        LIBRARY DESTINATION lib
        INCLUDES DESTINATION include
        PUBLIC_HEADER DESTINATION include)

install(EXPORT ${PROJECT_NAME}-export
    FILE rexer-config.cmake
    DESTINATION lib/cmake/rexer
    EXPORT_LINK_INTERFACE_LIBRARIES)
