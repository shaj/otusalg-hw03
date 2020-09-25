cmake_minimum_required(VERSION 3.2)

add_library(powlib STATIC pow.cpp)
set_target_properties(powlib PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
target_include_directories(powlib PUBLIC ${CMAKE_CURRENT_BINARY_DIR} )


add_library(fibolib STATIC fibo.cpp)
set_target_properties(fibolib PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
target_include_directories(fibolib PUBLIC ${CMAKE_CURRENT_BINARY_DIR} )
target_link_libraries(fibolib
	powlib
)


add_library(sievelib STATIC sieve.cpp)
set_target_properties(sievelib PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
target_include_directories(sievelib PUBLIC ${CMAKE_CURRENT_BINARY_DIR} )

