cmake_minimum_required(VERSION 3.15)

set (PROJECT_NAME Game)
project("${PROJECT_NAME}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("inc/")

add_executable("${PROJECT_NAME}" main.cpp 
				inc/Menu.hpp


				src/Menu.cpp
				)




include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries("${PROJECT_NAME}" sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

