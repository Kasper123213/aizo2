//
// Created by radom on 08.05.2024.
//

#include <fstream>
#include "Graph.h"

Graph::Graph(){
    vertices = 0;
    edges = 0;
}

Graph::~Graph() {
    clearRepresentations();
//    clearList(); //todo clearList
}


void Graph::readGraph(const string& path, char type) {
    clearRepresentations();

    // Otwórz plik
    ifstream file(path);

    // Sprawdź, czy udało się otworzyć plik
    if (!file.is_open()) {
        cerr << "Nieda się otworzyć pliku"<<endl;
        return;
    }

    // Wyczyść flagi błędów i pozycję odczytu pliku
    file.clear();
    file.seekg(0, ios::beg);

    file >> edges;
    file >> vertices;

    makeMatrix();
    int out, in, weight;

    try {
        int edgeID = 0;
        //Wczytywanie danych z pliku
        while (file >> out) {
            file >> in;
            file >> weight;
            addEdge(out, in, weight, edgeID, type);
            edgeID++;
        }
    }catch(const ifstream::failure& e){
        cerr << "Nieprawidłowy format pliku";
    }

    file.close();
}


void Graph::addEdge(int out, int in, int weight, int edgeID, char type) {
//    dodawanie do macierzy //todo uwzględnić krawędzie do samego siebie
    matrix[out]->setValue(edgeID, weight);

    if(matrix[in]->get(edgeID)==0) {//uwzględnienie krawędzi idących do tego samego wierzchołka z ktorego wychodzą
        if(type == 'D') {
            matrix[in]->setValue(edgeID, -weight);
        }else{
            matrix[in]->setValue(edgeID, weight);
        }
    }else{
        matrix[in]->setValue(edgeID, 2*weight);
    }

}

void Graph::clearRepresentations() {
    clearMatrix();
    clearList();

    vertices = 0;
    edges = 0;
}


void Graph::clearMatrix() {
    if(vertices == 0) return;
    for(int vertex = 0; vertex < vertices; vertex++){
        delete matrix[vertex];
    }

    delete[] matrix;
}


void Graph::makeMatrix() {
    matrix = new Table*[vertices];
    for(int vertex = 0; vertex <= vertices; vertex++){
        matrix[vertex] = new Table();
        matrix[vertex]->setSize(edges);
        matrix[vertex]->fillZeros();
    }
}


void Graph::clearList() {
    if(edges == 0) return;
    for(int edge = 0; edge < edges; edge++){
        for(int i=0; i<3; i++){
            delete list[edge][i];
        }
        delete[] list[edge];
    }
    delete[] list;
}


void Graph::makeList() {
    list = new Table**[edges];
    for(int edge = 0; edge <= edges; edge++){
        list[edge] = new Table*[3];
        for(int i=0; i<3; i++){
            list[edge][i] = new Table();
        }
    }
}
