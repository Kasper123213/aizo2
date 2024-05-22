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
    makeList();

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
//    uzupelnianie do macierzy
    matrix[out]->setValue(edgeID, weight);

    if(in != out) {//uwzględnienie krawędzi idących do tego samego wierzchołka z ktorego wychodzą
        //jesli krawędź jest pętlą to jest jedyna w kolumnie
        if(type == 'D') {//D- directed
            matrix[in]->setValue(edgeID, -weight);
        }else{
            matrix[in]->setValue(edgeID, weight);
        }
    }

// uzupelnianie listy
    list[out][0]->push(in);
    list[out][1]->push(weight);

    if(type == 'U' and out != in){
        list[in][0]->push(out);
        list[in][1]->push(weight);
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
    for(int vertex = 0; vertex < vertices; vertex++){
        matrix[vertex] = new Table();
        matrix[vertex]->setSize(edges);
        matrix[vertex]->fillZeros();
    }
}


void Graph::clearList() {
    if(vertices == 0) return;
    for(int vertex = 0; vertex < vertices; vertex++){
        for(int i=0; i<2; i++){
            delete list[vertex][i];
        }
        delete[] list[vertex];
    }
    delete[] list;
}


void Graph::makeList() {
    list = new Table**[vertices];
    for(int vertex = 0; vertex < vertices; vertex++){
        list[vertex] = new Table*[2];
        for(int i=0; i<2; i++){
            list[vertex][i] = new Table();
        }
    }
}

void Graph::printMatrix() {
    if(vertices == 0){
        cout<<"Macierz pusta"<<endl;
    }else{
        cout<<"Macierz incydencji:"<<endl;
        for(int row = 0; row<vertices; row++){
            cout<<row<<" -> ";
            for(int col = 0; col<edges; col++){
                cout<<matrix[row]->get(col)<<"\t| ";
            }
            cout<<endl;
        }
    }
}

void Graph::printList() {
    if(vertices == 0){
        cout<<"Lista pusta"<<endl;
    }else{
        cout<<"Lista następników:"<<endl;
        for(int row = 0; row<vertices; row++){
            cout<<row;
            for(int tab = 0; tab<2; tab++){
                   cout<<" -> {";
                   int size = list[row][tab]->getSize();
                   for(int i = 0; i<size-1; i++){
                       cout<<list[row][tab]->get(i)<<", ";
                   }
                   if(size>0) {
                       cout << list[row][tab]->get(list[row][tab]->getSize() - 1);
                   }
                   cout<<"}";
            }
            cout<<endl;
        }
    }
}
