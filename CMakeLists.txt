cmake_minimum_required(VERSION 3.10)

project(rstyle_parsing)

set(CMAKE_CXX_STANDARD 17)

add_executable(parse_data
        src/main.cpp
        src/document.cpp src/document.h
        src/node.cpp src/node.h
	)