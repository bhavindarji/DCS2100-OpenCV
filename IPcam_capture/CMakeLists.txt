cmake_minimum_required(VERSION 2.8)
project( capVideo )
find_package( OpenCV REQUIRED )
set(CMAKE_CXX_STANDARD 11)	# include C++ lib
set(CMAKE_CXX_STANDARD_REQUIRED ON) # include C++ lib
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable( cv_capVideo capVideo.cpp )
target_link_libraries( cv_capVideo ${OpenCV_LIBS} )
