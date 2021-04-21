cmake_minimum_required(VERSION 3.10)

# set the project name
project(SimpleDb)

# add the executable

add_executable(build.out main.cc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_definitions(-O2)
find_package(fmt REQUIRED)
target_link_libraries(build.out fmt::fmt)
find_package(LibXml2 REQUIRED)
target_link_libraries(build.out LibXml2::LibXml2)
