cmake_minimum_required(VERSION 3.5)
project(Program)

set(SOURCE_FILES
        src/main.cpp
        )

add_executable(Program ${SOURCE_FILES})

target_link_libraries(Program Biblioteka)

target_include_directories(Program PUBLIC include)

#enable_testing()                                           czy potrzebne będzie wykonywanie testów na programie?