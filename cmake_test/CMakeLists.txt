cmake_minimum_required (VERSION 3.14)

project(adsvel_circular_buffer_test)

set(CMAKE_CXX_STANDARD 17)

add_executable (
	${PROJECT_NAME} 
	${SRC_LIST} 
	"cmake_test.cpp" 
	"../adsvel_circular_buffer.h"
)

