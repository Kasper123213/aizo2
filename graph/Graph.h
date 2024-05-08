//
// Created by radom on 08.05.2024.
//

#ifndef AIZO2_GRAPH_H
#define AIZO2_GRAPH_H

#include <iostream>

using namespace std;
class Graph {

public:
    Graph();
    ~Graph();
    void readDirectedGraph(string path);
    void readUndirectedGraph(string path);
};


#endif //AIZO2_GRAPH_H
