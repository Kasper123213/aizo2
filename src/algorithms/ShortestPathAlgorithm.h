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

public:
    ShortestPathAlgorithm(Graph *graph, int start, int stop);
    ~ShortestPathAlgorithm();

    int start, stop;

    void startDijkstraWithMatrix();
    void startDijkstraWithList();

    void startBellmanFordWithMatrix();
    void startBellmanFordWithList();

    void showSolution();
    void update();
};


#endif //AIZO2_SHORTESTPATHALGORITHM_H
