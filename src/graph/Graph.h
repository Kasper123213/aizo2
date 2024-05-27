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
    void clearRepresentations();
    void clearMatrix();
    void makeMatrix();
    void clearList();
    void makeList();
    void addEdge(int out, int in, int weight, int edgeID, char type);
public:
    Graph();
    ~Graph();

    Table **matrix; //wierzchołek -> wagi kolejnych krawędzi //waga ujemna jesli krawedz idzie do, dodatnia jesli wychodzi
    Table ***list;//wierzchołek -> następnicy -> wagi następników

    int vertices;
    int edges;

    void readGraph(const string& path, char type);
    void printMatrix();
    void printList();

    void randomGraph(int vertices, int density, char type);

    void saveGraph();
};


#endif //AIZO2_GRAPH_H
