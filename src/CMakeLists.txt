include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(rexer SHARED
        hello.cpp
        world.cpp
        test/helloworld.cpp)
