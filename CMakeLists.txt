cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-SevvalKurt)

set(CMAKE_CXX_STANDARD 20)

add_library(graph-puzzle-game-SevvalKurt
        src/Graph.cpp
        src/Graph.h
        src/AbstractGraph.cpp
        src/AbstractGraph.cpp
        src/Path.cpp
        src/Path.h
        src/Edge.cpp
        src/Edge.h
        src/EdgeList.cpp
        src/EdgeList.h
        src/Node.h
        src/Node.cpp
        src/Queue.cpp
        src/Queue.h
        src/main.cpp)
