cmake_minimum_required(VERSION 3.2)

project(l3e)

add_executable(e e.cpp)

set_target_properties(e PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)


