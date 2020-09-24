cmake_minimum_required(VERSION 3.2)

project(l3e)

add_subdirectory(src)

add_executable(${PROJECT_NAME} app.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
target_link_libraries(${PROJECT_NAME}
	fibolib
	sievelib
)


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)


enable_testing()
add_subdirectory(test)
