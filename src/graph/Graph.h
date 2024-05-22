//
// Created by radom on 08.05.2024.
//

#ifndef AIZO2_GRAPH_H
#define AIZO2_GRAPH_H

#include <iostream>
#include "../structures/Table.h"

using namespace std;
class Graph {
private:
    Table **matrix; //wierzchołek -> wagi kolejnych krawędzi //waga ujemna jesli krawedz idzie do, dodatnia jesli wychodzi
    Table ***list;//wierzchołek -> następnicy -> wagi następników

    int vertices;
    int edges;

    void clearRepresentations();
    void clearMatrix();
    void makeMatrix();
    void clearList();
    void makeList();
    void addEdge(int out, int in, int weight, int edgeID, char type);
public:
    Graph();
    ~Graph();
    void readGraph(const string& path, char type);
    void printMatrix();
    void printList();
};


#endif //AIZO2_GRAPH_H
