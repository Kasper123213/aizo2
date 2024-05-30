//
// Created by radom on 29.05.2024.
//

#ifndef AIZO2_SHORTESTPATHALGORITHM_H
#define AIZO2_SHORTESTPATHALGORITHM_H


#include "../graph/Graph.h"

class ShortestPathAlgorithm {
private:
    Graph* graph;
    Table* paths;
    Table* weights;

    int start, stop;
public:
    ShortestPathAlgorithm(Graph *graph, int start, int stop);
    ~ShortestPathAlgorithm();

    void startDijkstraWithMatrix();
    void startDijkstraWithList();

    void startBellmanFordWithMatrix();
    void startBellmanFordWithList();

    void showSolution();
};


#endif //AIZO2_SHORTESTPATHALGORITHM_H
