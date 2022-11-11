cmake_minimum_required(VERSION 3.0)
project(rexer)

include(target_public_headers.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install CACHE PATH "install here" FORCE)

add_library(rexer SHARED hello.cpp world.cpp test/helloworld.cpp)

target_public_headers(rexer . include
        hello.h
        world.h
        test/helloworld.h)

install(TARGETS rexer
        EXPORT rexer-export
        LIBRARY         DESTINATION lib
        INCLUDES        DESTINATION include
        PUBLIC_HEADER   DESTINATION include/rexer)

install(EXPORT rexer-export
    FILE rexer-config.cmake
    DESTINATION lib/cmake/rexer/
    EXPORT_LINK_INTERFACE_LIBRARIES)
