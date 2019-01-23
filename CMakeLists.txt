cmake_minimum_required(VERSION 3.2)

project(l3e)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(GMP REQUIRED)

add_executable(e e.cpp)

set_target_properties(e PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(e gmp)


add_executable(p primesieve.cpp)

set_target_properties(p PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

