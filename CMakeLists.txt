cmake_minimum_required(VERSION 3.28)
project(aizo2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(aizo2 main.cpp tests/ManualTests.h tests/ManualTests.cpp tests/AutoTests.h tests/AutoTests.cpp graph/Graph.h graph/Graph.cpp)
