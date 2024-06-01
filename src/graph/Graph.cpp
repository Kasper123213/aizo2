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


void Graph::readGraph(const string& path) {
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
            addEdge(out, in, weight, edgeID);
            edgeID++;
        }
    }catch(const ifstream::failure& e){
        cerr << "Nieprawidłowy format pliku";
    }

    file.close();
}


void Graph::addEdge(int out, int in, int weight, int edgeID) {
//    uzupelnianie do macierzy
    matrix[out]->setValue(edgeID, weight);

    if(type == 'D') {//D- directed
        matrix[in]->setValue(edgeID, -weight);
    }else{
        matrix[in]->setValue(edgeID, weight);
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
        matrix[vertex]->setAllValues(0);
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

void Graph::printMatrix() {//todo popracowac nad wyswietlaniem macierzy
    int value;
    int maxLen;
    string tekstValue;
    if(type=='U') maxLen = 2;
    else maxLen = 3;

    if(vertices == 0){
        cout<<"Macierz pusta"<<endl;
    }else{
        cout<<"Macierz incydencji:"<<endl;
        for(int row = 0; row<vertices; row++){
            cout<<row<<" ->";
            for(int col = 0; col<edges; col++){
                value = matrix[row]->get(col);
                tekstValue = to_string(value);
                cout<<tekstValue + string(maxLen - tekstValue.length(), ' ')<<"|";
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

void Graph::randomGraph(int vertices, int density) {//todo ulepszyc generowanie na przyklad losowanie  krawedzi z puli
    clearRepresentations();//todo krawedzie w dwie strony powinny miec rozne wagi

    this->vertices = vertices;

    if(type == 'U'){
        this->edges = int(density/100.0 * vertices * (vertices-1) / 2);
    }else{
        this->edges = int(density/100.0 * vertices * (vertices-1));
    }

    makeMatrix();
    makeList();
    //tworzenie drzewa spinającego
    Table* visited = new Table();
    Table* unvisited = new Table();

    for(int v=1; v<vertices; v++){
        unvisited->push(v);
    }
    visited->push(0);

    int from, to, weight, vertex, edgeId = 0;
    while (unvisited->getSize()!=0) {
        from = rand() % (visited->getSize());
        to = rand() % (unvisited->getSize());

        if(from == to)continue;

        weight = rand() % (99)+1;

        vertex = unvisited->get(to);
        addEdge(visited->get(from), vertex, weight, edgeId);
        edgeId++;
        if(type == 'D'){//podwojenie drzewa aby zapewnic sciezki miedzy dwoma dowolnymi wierzcholkami
            weight = rand() % (99)+1;
            addEdge(vertex, visited->get(from), weight, edgeId);
            edgeId++;
        }

        visited->push(vertex);
        unvisited->remove(to);
    }

    int vertexFrom, vertexTo;
    //dodawanie reszty krawędzi
    while(edgeId<edges){
        from = rand() % (visited->getSize());
        to = rand() % (visited->getSize());

        if(from != to and list[from][0]->find(to) == -1) {
            weight = rand() % (99) + 1;//todo zmienic maxa
            addEdge(from, to, weight, edgeId);
            edgeId++;
        }
    }

    delete visited;
    delete unvisited;
}


//zapisanie rozwiązania do pliku
void Graph::saveGraph() {
    int index = 1;
    string name;
    while (true) {
        name = "graph" + to_string(index) + ".txt";
        ifstream file(name);
        if (not file.good()) break;
        index++;
    }

    // Otwarcie pliku w trybie do zapisu (truncation)
    ofstream file1(name, ios::trunc);

    int from, to, weight;
    // Sprawdzenie, czy plik został otwarty poprawnie
    if (file1.is_open()) {
        file1 << edges << " " << vertices << endl;

        for (int edge = 0; edge < edges; edge++) {
            from = -1;
            to = -1;
            for(int vertex = 0; vertex<vertices; vertex++){
                if(matrix[vertex]->get(edge) > 0){
                    if(from == -1) {
                        from = vertex;
                    }else{
                        to = vertex;
                    }
                    weight = matrix[vertex]->get(edge);
                }else if(matrix[vertex]->get(edge) < 0){
                    to = vertex;
                }
            }

            file1 << from << " " << to << " " << weight << endl;
        }
        file1.close();

        cout << "Zapisano do pliku." << endl;
    } else {
        cout << "Błąd podczas otwierania pliku." << endl;
    }
}

void Graph::setType(char type) {
    this->type = type;
}

