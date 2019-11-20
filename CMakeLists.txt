cmake_minimum_required(VERSION 3.2)

project(l3e)

add_executable(l3 main.cpp l3.cpp p3.cpp)

set_target_properties(l3 PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)


add_executable(p primesieve.cpp)

set_target_properties(p PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

