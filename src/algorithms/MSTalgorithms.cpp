#include <limits>
#include "MSTalgorithms.h"

MSTalgorithms::MSTalgorithms(Graph* graph) {
    this->graph = graph;
    mstWeight = 0;
    makeList();
    sets = new Table();
}

MSTalgorithms::~MSTalgorithms() {
    clearMST();
    delete sets;
}


void MSTalgorithms::printMST() {
    int vertices = graph->vertices;
    if(vertices == 0){
        cout<<"Lista pusta"<<endl;
    }else{
        cout<<"Lista następników:"<<endl;
        for(int row = 0; row<vertices; row++){
            cout<<row;
            for(int tab = 0; tab<2; tab++){
                cout<<" -> {";
                int size = mst[row][tab]->getSize();
                for(int i = 0; i<size-1; i++){
                    cout<<mst[row][tab]->get(i)<<", ";
                }
                if(size>0) {
                    cout << mst[row][tab]->get(mst[row][tab]->getSize() - 1);
                }
                cout<<"}";
            }
            cout<<endl;
        }
    }
}


void MSTalgorithms::addToMST(int from, int to, int weight) {
    mst[from][0]->push(to);
    mst[from][1]->push(weight);

    if(from != to){
        mst[to][0]->push(from);
        mst[to][1]->push(weight);
    }
}


void MSTalgorithms::clearMST() {
    if(graph->vertices == 0) return;
    for(int vertex = 0; vertex < graph->vertices; vertex++){
        for(int i=0; i<2; i++){
            delete mst[vertex][i];
        }
        delete[] mst[vertex];
    }
    delete[] mst;
}


void MSTalgorithms::makeList() {
    mst = new Table**[graph->vertices];
    for(int vertex = 0; vertex < graph->vertices; vertex++){
        mst[vertex] = new Table*[2];
        for(int i=0; i<2; i++){
            mst[vertex][i] = new Table();
        }
    }
}



//////////////////////////////////////////////////////////////////////////////////////
///     Algorytm Prima
///     Z użyciem macierzy
//////////////////////////////////////////////////////////////////////////////////////

void MSTalgorithms::startPrimWithMatrix() {
    Table* visited = new Table();
    Table* unvisited = new Table();

    for(int i=1; i<graph->vertices; i++){
        unvisited->push(i);
    }
    visited->push(0);

    int minVertex_from, minVertex_to, minEdge, minWeight, currentWeight, currentVertex, nextVertex;
    while(unvisited->getSize()!=0){
        minEdge = 0;
        minVertex_from = visited->get(0);;
        minWeight = numeric_limits<int>::max();

        for(int vertexId=0; vertexId<visited->getSize(); vertexId++){ //dla każdego wierzchołka odwiedzonego
            for(int edge=0; edge<graph->edges; edge++){     //szukamy krawędzi
                currentVertex = visited->get(vertexId);
                currentWeight = graph->matrix[currentVertex]->get(edge);
                if(currentWeight <= 0) continue;
                for(nextVertex=0; nextVertex < graph->vertices; nextVertex++){   //która nie prowadzi do już odwiedzonego wierzchołka
                    if(graph->matrix[nextVertex]->get(edge) != 0 and visited->find(nextVertex)==-1){
                        if(currentWeight < minWeight){
                            minWeight = currentWeight;
                            minVertex_from = currentVertex;
                            minVertex_to = nextVertex;
                            minEdge = edge;
                        }

                        break;
                    }
                }
            }
        }
        //mamy krawędź z najmniejszą wagą wychodzącą z odwiedzonych już wierzchołków do nieodwiedzonych
        //dodawanie wierzchołka do odwiedzonych
        int vertexId = unvisited->find(minVertex_to);
        unvisited->remove(vertexId);
        visited->push(minVertex_to);

        mstWeight+=minWeight;
        addToMST(minVertex_from, minVertex_to, minWeight);

    }
    delete visited;
    delete unvisited;
    printMST();//todo przenieść gdzieś
    cout<<"koszt: "<<mstWeight<<endl;
}


//////////////////////////////////////////////////////////////////////////////////////
///     Algorytm Prima
///     Z użyciem listy
//////////////////////////////////////////////////////////////////////////////////////

void MSTalgorithms::startPrimWithList() {
    Table* visited = new Table();
    Table* unvisited = new Table();

    for(int i=1; i<graph->vertices; i++){
        unvisited->push(i);
    }
    visited->push(0);

    int minVertex_from, minVertex_to, minEdge, minWeight, currentWeight, currentVertex, nextVertex;
    while(unvisited->getSize()!=0){
        minEdge = 0;
        minVertex_from = visited->get(0);
        minWeight = numeric_limits<int>::max();

        for(int vertexId=0; vertexId<visited->getSize(); vertexId++){ //dla każdego wierzchołka odwiedzonego
            currentVertex = visited->get(vertexId);
            for(int edge=0; edge<graph->list[currentVertex][0]->getSize(); edge++){     //szukamy następnika
                currentWeight = graph->list[currentVertex][1]->get(edge);
                nextVertex = graph->list[currentVertex][0]->get(edge);
                if(visited->find(nextVertex) == -1){ //który nie był już odwiedzony
                    if(currentWeight < minWeight){      //i do którego koszt jest najmniejszy
                            minWeight = currentWeight;
                            minVertex_from = currentVertex;
                            minVertex_to = nextVertex;
                            minEdge = edge;
                    }
                }
            }
        }
        //mamy krawędź z najmniejszą wagą wychodzącą z odwiedzonych już wierzchołków do nieodwiedzonych
        //dodawanie wierzchołka do odwiedzonych
        int vertexId = unvisited->find(minVertex_to);
        unvisited->remove(vertexId);
        visited->push(minVertex_to);

        mstWeight+=minWeight;
        addToMST(minVertex_from, minVertex_to, minWeight);

    }
    delete visited;
    delete unvisited;
    printMST();//todo przenieść gdzieś
    cout<<"koszt: "<<mstWeight<<endl;
}

void MSTalgorithms::startKruskalWithMatrix() {
    for(int i=0; i<graph->vertices; i++){
        sets->push(i);
    }

    Table* edges = new Table();
    for(int i=0; i<graph->edges; i++){
        edges->push(i);
    }

    int minWeight, minEdge, minVertex1, minVertex2, vertex1, vertex2, vertex1Group, vertex2Group, minVertex1Group, minVertex2Group, currentWeight;
    int neededEdges = graph->vertices - 1;
    while(neededEdges>0){   //Szukamy n-1 krawędzi
        minEdge = -1;
        minVertex1 = -1;
        minVertex2 = -1;
        minWeight = numeric_limits<int>::max();
        for(int edge=0; edge<edges->getSize(); edge++){ //sprawdzamy każdą krawędź
            vertex1 = -1;
            vertex2 = -1;
            for(int vertex=0; vertex<graph->vertices; vertex++){    //szukamy w niej wierzchołków incydentnych
                currentWeight = graph->matrix[vertex]->get(edges->get(edge));
                if(currentWeight != 0 and currentWeight<minWeight){ //jeśli koszt drogi jest najmniejszy
                    if(vertex1 == -1) {
                        vertex1 = vertex;
                        continue;
                    }
                    else vertex2 = vertex;

                    vertex1Group = findGroup(vertex1);
                    vertex2Group = findGroup(vertex2);
                    if(vertex1Group != vertex2Group){       //pod warunkiem, że krawędzie nie tworzą cyklu
                        minVertex1Group = vertex1Group;     //zapamiętujemy dane
                        minVertex2Group = vertex2Group;
                        minWeight = currentWeight;
                        minVertex1 = vertex1;
                        minVertex2 = vertex2;
                        minEdge = edge;
                        break;
                    }
                }
            }
        }
        edges->remove(minEdge);                                     //niepotrzebną krawędź usuwamy
        sets->setValue(minVertex1Group, minVertex2Group);// a dane zapisujemy do obiektu
        addToMST(minVertex1, minVertex2, minWeight);
        mstWeight += minWeight;
        neededEdges--;

    }

    delete edges;
    printMST();
    cout<<"Koszt: "<<mstWeight<<endl;//todo przeniesc to gdzies


}

int MSTalgorithms::findGroup(int vertex) {
    if(sets->get(vertex) == vertex) return vertex;
    else return findGroup(sets->get(vertex));
}

void MSTalgorithms::startKruskalWithList() {
    for(int i=0; i<graph->vertices; i++){
        sets->push(i);
    }
    
    int minVertex1, minVertex2, minWeight, minVertex1Group, minVertex2Group, currentWeight, successor, vertex1Group, vertex2Group;
    int neededEdges = graph->vertices - 1;
    while(neededEdges>0) {   //Szukamy n-1 krawędzi
        minVertex1 = -1;
        minVertex2 = -1;
        minVertex1Group = 0;
        minVertex2Group = 0;
        minWeight = numeric_limits<int>::max();

        for(int vertex=0; vertex<graph->vertices; vertex++){
            for(int successorId=0; successorId<graph->list[vertex][0]->getSize(); successorId++){
                currentWeight = graph->list[vertex][1]->get(successorId);
                successor = graph->list[vertex][0]->get(successorId);
                vertex1Group = findGroup(vertex);
                vertex2Group = findGroup(successor);
                if(currentWeight<minWeight and vertex1Group != vertex2Group){
                    minWeight = currentWeight;
                    minVertex1 = vertex;
                    minVertex2 = successor;
                    minVertex1Group = vertex1Group;
                    minVertex2Group = vertex2Group;
                }
            }
        }
        sets->setValue(minVertex1Group, minVertex2Group);
        addToMST(minVertex1, minVertex2, minWeight);
        mstWeight+=minWeight;
        neededEdges--;
    }

    printMST();
    cout<<"Koszt: "<<mstWeight<<endl;//todo przeniesc to gdzies
    
}
