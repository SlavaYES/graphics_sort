cmake_minimum_required(VERSION 3.17)
project(first_test)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(first_test main.cpp SourceArray.cpp SourceArray.h)

target_link_libraries(first_test sfml-graphics)