

#include <fstream>
#include "AutoTests.h"
#include "Time.h"
#include "../graph/Graph.h"
#include "../algorithms/MSTalgorithms.h"
#include "../algorithms/ShortestPathAlgorithm.h"

AutoTests::AutoTests(){
    Time *time = new Time();

    long algorithmTime;
    int* densities = new int[3];
    densities[0] = 25;
    densities[1] = 50;
    densities[2] = 99;

    Graph* graph = new Graph();

//mst
    graph->setType('U');
    MSTalgorithms* mstalgorithm = new MSTalgorithms(graph);

    //prim matrix
    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje


    string primMatrix = "PrimAlgorithmMatrix.csv";
    ofstream primMatrixF(primMatrix, ios::app);

    string primList = "PrimAlgorithmList.csv";
    ofstream primListF(primList, ios::app);

    string kruskalMatrix = "KruskalAlgorithmMatrix.csv";
    ofstream kruskalMatrixF(kruskalMatrix, ios::app);

    string kruskalList = "KruskalAlgorithmList.csv";
    ofstream kruskalListF(kruskalList, ios::app);

    cout<<"MST"<<endl;
    for(int densityID=0; densityID<3; densityID++){
        cout<<"\tgęstość "<<densities[densityID]<<endl;
        for(int size=100; size<=700; size+=100){
            cout<<"\t\trozmiar "<<size<<endl;
            for(int i=0; i<50; i++) {
                cout<<"\t\t\titeracja"<<i<<endl;
                graph->randomGraph(size, densities[densityID], numeric_limits<int>::max()-1);


                mstalgorithm->update();
                cout<<"\t\t\t\tprim na macierzy"<<endl;
                time->start();
                mstalgorithm->startPrimWithMatrix();
                algorithmTime = time->getTimeMiliseconds();
                primMatrixF << algorithmTime << ";";

                cout<<"\t\t\t\tprim na liście"<<endl;
                mstalgorithm->clearMST();
                mstalgorithm->update();
                time->start();
                mstalgorithm->startPrimWithList();
                algorithmTime = time->getTimeMiliseconds();
                primListF << algorithmTime << ";";

                cout<<"\t\t\t\tkruskal na macierzy"<<endl;
                mstalgorithm->clearMST();
                mstalgorithm->clearSets();
                mstalgorithm->update();
                time->start();
                mstalgorithm->startKruskalWithMatrix();
                algorithmTime = time->getTimeMiliseconds();
                kruskalMatrixF << algorithmTime << ";";

                cout<<"\t\t\t\tkruskal na liście"<<endl;
                mstalgorithm->clearMST();
                mstalgorithm->clearSets();
                mstalgorithm->update();
                time->start();
                mstalgorithm->startKruskalWithList();
                algorithmTime = time->getTimeMiliseconds();
                kruskalListF << algorithmTime << ";";


            }
            primMatrixF <<endl;
            primListF <<endl;
            kruskalMatrixF <<endl;
            kruskalListF <<endl;
        }
    }
    primMatrixF.close();
    primListF.close();
    kruskalMatrixF.close();
    kruskalListF.close();
    cout<<"Koniec algorytmów MST"<<endl;


    delete mstalgorithm;
//scieżka
    graph->setType('D');
    ShortestPathAlgorithm* shortestPathAlgorithm = new ShortestPathAlgorithm(graph, 0, 399);

    //dijkstra matrix
    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
    string dijkstraMatrix = "DijkstraAlgorithmMatrix.csv";
    ofstream dijkstraMatrixF(dijkstraMatrix, ios::app);

    string dijkstraList = "DijkstraAlgorithmList.csv";
    ofstream dijkstraListF(dijkstraList, ios::app);

    string bellmanFordMatrix = "BellmanFordAlgorithmMatrix.csv";
    ofstream bellmanFordMatrixF(bellmanFordMatrix, ios::app);

    string bellmanFordList = "BellmanFordAlgorithmList.csv";
    ofstream bellmanFordListF(bellmanFordList, ios::app);




    cout<<"Algorytmy najkrótszej ścieżki"<<endl;
    for(int densityID=0; densityID<3; densityID++){
        cout<<"\tGęstość "<<densities[densityID]<<endl;
        for(int size=300; size<=900; size+=100){
            cout<<"\t\trozmiar "<<size<<endl;
            graph->randomGraph(size, densities[densityID], numeric_limits<int>::max()-1);
            for(int i=0; i<50; i++) {
                cout<<"\t\t\titeracja "<<i<<endl;
                shortestPathAlgorithm->start = i+1;

                cout<<"\t\t\t\tdijkstra na macierzy"<<endl;
                shortestPathAlgorithm->update();
                time->start();
                shortestPathAlgorithm->startDijkstraWithMatrix();
                algorithmTime = time->getTimeMiliseconds();
                dijkstraMatrixF << algorithmTime << ";";

                cout<<"\t\t\t\tdijkstra na liście"<<endl;
                shortestPathAlgorithm->update();
                time->start();
                shortestPathAlgorithm->startDijkstraWithList();
                algorithmTime = time->getTimeMiliseconds();
                dijkstraListF << algorithmTime << ";";

                cout<<"\t\t\t\tbellmanFord na macierzy"<<endl;
                shortestPathAlgorithm->update();
                time->start();
                shortestPathAlgorithm->startBellmanFordWithMatrix();
                algorithmTime = time->getTimeMiliseconds();
                bellmanFordMatrixF << algorithmTime << ";";

                cout<<"\t\t\t\tbellmanFord na liście"<<endl;
                shortestPathAlgorithm->update();
                time->start();
                shortestPathAlgorithm->startBellmanFordWithList();
                algorithmTime = time->getTimeMiliseconds();
                bellmanFordListF << algorithmTime << ";";

            }
            dijkstraMatrixF << endl;
            dijkstraListF << endl;
            bellmanFordMatrixF << endl;
            bellmanFordListF << endl;

        }
    }

    dijkstraMatrixF.close();
    dijkstraListF.close();
    bellmanFordMatrixF.close();
    bellmanFordListF.close();
    cout<<"Koniec algorytmu dijkstry na macierzy"<<endl;


    delete shortestPathAlgorithm;

    delete graph;
    delete time;
}

AutoTests::~AutoTests() {

}
