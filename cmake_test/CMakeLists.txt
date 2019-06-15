cmake_minimum_required (VERSION 3.14)

project(adsvel_circular_buffer_test)

set(CMAKE_CXX_STANDARD 17)

# The boost library linking. 
set (Boost_USE_STATIC_LIBS ON)     
set (Boost_USE_MULTITHREADED OFF)   
find_package(Boost REQUIRED)
include_directories (SYSTEM ${Boost_INCLUDE_DIR}) 
link_directories(${Boost_LIBRARIES})

add_executable (
	${PROJECT_NAME} 
	${SRC_LIST} 
	"cmake_test.cpp" 
	"../adsvel_circular_buffer.h"
)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})