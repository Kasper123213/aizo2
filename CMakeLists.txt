cmake_minimum_required(VERSION 3.28)
project(aizo2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(aizo2 src/main.cpp src/tests/ManualTests.h src/tests/ManualTests.cpp src/tests/AutoTests.h src/tests/AutoTests.cpp src/graph/Graph.h src/graph/Graph.cpp src/structures/Table.h src/structures/Table.cpp src/algorithms/Prim.h src/algorithms/Prim.cpp src/algorithms/Kruskal.cpp src/algorithms/Kruskal.h src/algorithms/Dijkstra.cpp src/algorithms/Dijkstra.h src/algorithms/FordBellman.cpp src/algorithms/FordBellman.h)
