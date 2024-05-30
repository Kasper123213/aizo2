//
// Created by radom on 29.05.2024.
//

#include <limits>
#include "ShortestPathAlgorithm.h"

ShortestPathAlgorithm::ShortestPathAlgorithm(Graph *graph, int start, int stop) {
    this->graph = graph;
    this->start = start;
    this->stop = stop;

    paths = new Table();
    paths->setSize(graph->vertices);
    paths->setAllValues(-1);

    weights = new Table();
    weights->setSize(graph->vertices);
    weights->setAllValues(-1);
}

ShortestPathAlgorithm::~ShortestPathAlgorithm() {
    delete paths;
    delete weights;
}


//////////////////////////////////////////////////////////////////////////////////////
///     Algorytm Dijkstra
///     Z użyciem macierzy
//////////////////////////////////////////////////////////////////////////////////////


void ShortestPathAlgorithm::startDijkstraWithMatrix() {
    Table* neighbours = new Table();
    Table* neighboursEdges = new Table();
    Table* s = new Table();
    Table* q = new Table();
    for(int vertex=0; vertex<graph->vertices;vertex++){
        q->push(vertex);
    }

    weights->setSize(graph->vertices);
    paths->setSize(graph->vertices);

    weights->setAllValues(numeric_limits<int>::max());
    weights->setValue(start, 0);

    paths->setAllValues(-1);

    int vertex, value, minValue, minVertexId, minVertex, neighbour, newWeight;

    while(q->getSize()>0){
        minValue = numeric_limits<int>::max();
        //minimalna wartosc w zbiorze q
        for(int vertexId=0; vertexId<q->getSize();vertexId++){
            vertex = q->get(vertexId);
            value = weights->get(vertex);
            if(value<minValue){
                minVertex = vertex;
                minValue = value;
                minVertexId = vertexId;
            }
        }
        //przenoszenie jej do s
        s->push(weights->get(minVertexId));
        q->remove(minVertexId);

        //szukanie sąsiadów wierzchołka
        for(int edge=0; edge<graph->edges; edge++){
            if(graph->matrix[minVertex]->get(edge)>0){
                for(int vertex2=0; vertex2<graph->vertices; vertex2++){
                    if(graph->matrix[vertex2]->get(edge)<0){
                        neighbours->push(vertex2);
                        neighboursEdges->push(edge);
                    }
                }
            }
        }
        // przeszukiwanie sąsiadów
        for(int neighbourId=0; neighbourId<neighbours->getSize(); neighbourId++){
            neighbour = neighbours->get(neighbourId);
            if(q->find(neighbour)!=-1){
                newWeight = weights->get(minVertex)+graph->matrix[minVertex]->get(neighboursEdges->get(neighbourId));
                if(weights->get(neighbour)>newWeight){
                    weights->setValue(neighbour,newWeight);
                    paths->setValue(neighbour, minVertex);
                }
            }
        }

        neighbours->clear();
        neighboursEdges->clear();

    }

    paths->setValue(start, start);
    delete q;
    delete s;
    delete neighboursEdges;
    delete neighbours;

}


//////////////////////////////////////////////////////////////////////////////////////
///     Algorytm Dijkstra
///     Z użyciem listy
//////////////////////////////////////////////////////////////////////////////////////

void ShortestPathAlgorithm::startDijkstraWithList() {
    Table* s = new Table();
    Table* q = new Table();
    for(int vertex=0; vertex<graph->vertices;vertex++){
        q->push(vertex);
    }

    weights->setSize(graph->vertices);
    paths->setSize(graph->vertices);

    weights->setAllValues(numeric_limits<int>::max());
    weights->setValue(start, 0);

    paths->setAllValues(-1);

    int vertex, value, minValue, minVertexId, minVertex, neighbour, newWeight;

    while(q->getSize()>0){
        minValue = numeric_limits<int>::max();
        //minimalna wartosc w zbiorze q
        for(int vertexId=0; vertexId<q->getSize();vertexId++){
            vertex = q->get(vertexId);
            value = weights->get(vertex);
            if(value<minValue){
                minVertex = vertex;
                minValue = value;
                minVertexId = vertexId;
            }
        }
        //przenoszenie jej do s
        s->push(weights->get(minVertexId));
        q->remove(minVertexId);


        // przeszukiwanie sąsiadów
        for(int neighbourId=0; neighbourId<graph->list[minVertex][0]->getSize(); neighbourId++){
            neighbour = graph->list[minVertex][0]->get(neighbourId);
            if(q->find(neighbour)!=-1){
                newWeight = weights->get(minVertex)+graph->list[minVertex][1]->get(neighbourId);
                if(weights->get(neighbour)>newWeight){
                    weights->setValue(neighbour,newWeight);
                    paths->setValue(neighbour, minVertex);
                }
            }
        }
    }

    paths->setValue(start, start);

    delete q;
    delete s;
}


//////////////////////////////////////////////////////////////////////////////////////
///     Algorytm Bellman Ford
///     Z użyciem macierzy
//////////////////////////////////////////////////////////////////////////////////////

void ShortestPathAlgorithm::startBellmanFordWithMatrix() {
    weights->setAllValues(numeric_limits<int>::max());
    paths->setAllValues(-1);

    weights->setValue(start, 0);
    paths->setValue(start, start);



    int vertexFrom, vertexTo, newWeight;
    bool changes;
    for(int i=0; i<graph->vertices-1; i++){
        changes = false;
        for(int edge=0; edge<graph->edges; edge++) {
            //szukanie incydentnych wierzchołków
            for(int vertex=0; vertex<graph->vertices; vertex++) {
                if(graph->matrix[vertex]->get(edge)>0){
                    vertexFrom = vertex;
                }else if(graph->matrix[vertex]->get(edge)<0){
                    vertexTo = vertex;
                }
            }


            if(paths->get(vertexFrom)==-1)continue; //jesli wierzchołek jeszcze nie zbadany to pomijamy iterację
            newWeight = weights->get(vertexFrom) + graph->matrix[vertexFrom]->get(edge);
            if(newWeight<0) newWeight = numeric_limits<int>::max();
            if(weights->get(vertexTo) > newWeight){
                weights->setValue(vertexTo, newWeight);
                paths->setValue(vertexTo, vertexFrom);
                changes = true;
            }
        }
        if(!changes) break;
    }
}



//////////////////////////////////////////////////////////////////////////////////////
///     Algorytm Bellman Ford
///     Z użyciem listy
//////////////////////////////////////////////////////////////////////////////////////

void ShortestPathAlgorithm::startBellmanFordWithList() {
    weights->setAllValues(numeric_limits<int>::max());
    paths->setAllValues(-1);

    weights->setValue(start, 0);
    paths->setValue(start, start);


    int vertexTo, newWeight;
    bool changes;
    for(int i=0; i<graph->vertices-1; i++){
        changes = false;

        int vertexFrom = 0;//zamienic
        for(int vertexToId=0; vertexFrom<graph->vertices; vertexToId++){//iterowanie po następnikach wierzchołków
            if(vertexToId >= graph->list[vertexFrom][0]->getSize()){//czyli po każdej krawędzi
                vertexToId = -1;
                vertexFrom++;
                continue;
            }

            vertexTo = graph->list[vertexFrom][0]->get(vertexToId);
            newWeight = weights->get(vertexFrom) + graph->list[vertexFrom][1]->get(vertexToId);
            if(newWeight<0) newWeight = numeric_limits<int>::max();
            if(weights->get(vertexTo)>newWeight){
                weights->setValue(vertexTo, newWeight);
                paths->setValue(vertexTo, vertexFrom);
                changes = true;
            }
        }

        if(!changes) break;
    }
}

void ShortestPathAlgorithm::showSolution() {
    cout<<"Koszt dojścia z wierzchołka "<<start<<" do wierzchołka "<<stop<<" wynosi: "<<weights->get(stop)<<endl;
    cout<<"Ścieżka to:"<<endl;
    Table* solution = new Table();

    int nextVertex = stop;
    do{
        solution->push(nextVertex);
        nextVertex = paths->get(nextVertex);
    }while(nextVertex != start);
    solution->push(start);

    for(int i=solution->getSize()-1; i>0; i--){
        cout<<solution->get(i)<<"->";
    }
    cout<<solution->get(0)<<endl;

    delete solution;
}
