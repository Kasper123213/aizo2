//
// Created by radom on 23.05.2024.
//

#ifndef AIZO2_MSTALGORITHMS_H
#define AIZO2_MSTALGORITHMS_H

#include "../graph/Graph.h"

class MSTalgorithms {
private:
    Graph* graph;
    Table ***mst;//wierzchołek -> następnicy -> wagi następników

    //potrzebne do kruskala
    Table* parents;

    int mstWeight;
    void addToMST(int from, int to, int weight);
    void clearList();
    void makeList();
public:
    MSTalgorithms (Graph* graph);
    ~MSTalgorithms();

    void printMST();

    void startPrimWithMatrix();
    void startPrimWithList();

    void startKruskalWithMatrix();
    void startKruskalWithList();

    int findGroup(int vertex);
};

#endif //AIZO2_MSTALGORITHMS_H
