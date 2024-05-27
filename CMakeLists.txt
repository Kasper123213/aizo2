cmake_minimum_required(VERSION 3.28)
project(aizo2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(aizo2 src/main.cpp src/tests/ManualTests.h src/tests/ManualTests.cpp src/tests/AutoTests.h src/tests/AutoTests.cpp src/graph/Graph.h src/graph/Graph.cpp src/structures/Table.h src/structures/Table.cpp src/algorithms/MSTalgorithms.cpp src/algorithms/MSTalgorithms.h)
