cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -ldl")
project( Project )
find_package( OpenCV REQUIRED )
 
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable( Main.out main.cpp ./Engine/Engine.cpp)
target_link_libraries( Main.out ${OpenCV_LIBS})
