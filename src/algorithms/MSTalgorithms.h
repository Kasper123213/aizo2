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
    Table* sets;

    void addToMST(int from, int to, int weight);
    void clearMST();
    void makeMST();
    int findGroup(int vertex);
public:
    MSTalgorithms (Graph* graph);
    ~MSTalgorithms();

    void printMST();
    void update();

    void startPrimWithMatrix();
    void startPrimWithList();

    void startKruskalWithMatrix();
    void startKruskalWithList();


    int mstWeight;
};

#endif //AIZO2_MSTALGORITHMS_H
