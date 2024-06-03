////
//// Created by radom on 08.05.2024.
////
//
//#include <fstream>
//#include "AutoTests.h"
//#include "Time.h"
//#include "../graph/Graph.h"
//#include "../algorithms/MSTalgorithms.h"
//#include "../algorithms/ShortestPathAlgorithm.h"
//
////todo autotests
//
////prim list 25 400=1  500=3.6  1000=56
////prim list 50 400=3
////prim list 99 400=6  600=32  800= 95 1000=233   400, 550, 700, 850, 1000, 1150, 1300
////prim matrix 25 100=0.65
////prim matrix 50 220=6
////prim matrix 99 220=17
////        100 - 700
//
////kruskal list 25 400=1
////kruskal list 50 400=5
////kruskal list 99 400=15
////kruskal matrix 25  220=1
////kruskal matrix 50 220=3
////kruskal matrix 99 220=8
////        100 - 700
//
////dijkstra list 25 2000 = 0.735
////dijkstra list 50 2000 = 1.415
////dijkstra list 99 2000 = 2.818
////dijkstra matrix 25 600 = 1
////dijkstra matrix 50 600=2
////dijkstra matrix 99 600=5
//    //400, 500, 600, 700, 800, 900, 1000
//
////bellmanford list 25 2000 = 0.039  500 wierzcchołków = 3ms
////bellmanford list 50 2000 = 0.073
////bellmanford list 99 2000 = 0.106
////bellmanford matrix 25 600 = 2
////bellmanford matrix 50 600 = 2
////bellmanford matrix 99 600=7
//    //400, 500, 600, 700, 800, 900, 1000
//
//
////32323ms gemeruje sie 99% graf 1500 wierzchołków
////69446ms gemeruje sie 99% graf 2000 wierzchołków
//
////7 reprezentatywnych wielkosci
//// Dla każdego zestawu: reprezentacja,
//// liczba wierzchołków i gęstość należy
//// wygenerować serię losowych instancji (np. 50
//AutoTests::AutoTests(){//todo do tworzenia grafu dodac mozliowsc zwiekszenia ilosci krawedzi w grafie np z 25 na 50
//    Time *time = new Time();
//
//    long algorithmTime;
//    int* densities = new int[3];
//    densities[0] = 25;
//    densities[1] = 50;
//    densities[2] = 99;
//
//    Graph* graph = new Graph();
//
////mst
//    graph->setType('U');
//    MSTalgorithms* mstalgorithm = new MSTalgorithms(graph);
//
//    //prim matrix
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    string name = "PrimAlgorithmMatrix.csv";
//    ofstream file(name, ios::app);  //otwieranie pliku
//
//    cout<<"Prim z macierzą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=100; size<=700; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                graph->randomGraph(size, densities[densityID]);
//                mstalgorithm->update();
//                time->start();
//                mstalgorithm->startPrimWithMatrix();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu Prima na macierzy"<<endl;
//
//
//
//
//
//    //prim list
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "PrimAlgorithmList.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//    cout<<"Prim z listą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=100; size<=700; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                graph->randomGraph(size, densities[densityID]);
//                mstalgorithm->update();
//                time->start();
//                mstalgorithm->startPrimWithList();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu Prima na listą"<<endl;
//
//
//
//
//
//
//
//
//    //kruskal matrix
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "KruskalAlgorithmMatrix.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//    cout<<"Kruskal z macierzą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=100; size<=700; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                graph->randomGraph(size, densities[densityID]);
//                mstalgorithm->update();
//                time->start();
//                mstalgorithm->startKruskalWithMatrix();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu Kruskala na macierzy"<<endl;
//
//
//
//
//
//    //kruskal list
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "KruskalAlgorithmList.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//    cout<<"Kruskal z listą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=100; size<=700; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                graph->randomGraph(size, densities[densityID]);
//                mstalgorithm->update();
//                time->start();
//                mstalgorithm->startKruskalWithList();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu Kruskala na listą"<<endl;
//
//
//    delete mstalgorithm;
////scieżka
//    graph->setType('D');
//    ShortestPathAlgorithm* shortestPathAlgorithm = new ShortestPathAlgorithm(graph, 0, 399);
//
//    //dijkstra matrix
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "DijkstraAlgorithmMatrix.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//
//    cout<<"Dijkstra z macierzą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=400; size<=1000; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            graph->randomGraph(size, densities[densityID]);
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                shortestPathAlgorithm->start = i+1;
//                shortestPathAlgorithm->update();
//                time->start();
//                shortestPathAlgorithm->startDijkstraWithMatrix();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu dijkstry na macierzy"<<endl;
//
//
//
//
//
//
//    //dijkstra  list
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "DijkstraAlgorithmList.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//
//    cout<<"Dijkstra z listą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=400; size<=1000; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            graph->randomGraph(size, densities[densityID]);
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                shortestPathAlgorithm->update();
//                shortestPathAlgorithm->start = i+1;
//                time->start();
//                shortestPathAlgorithm->startDijkstraWithList();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu dijkstry na listą"<<endl;
//
//
//
//
//    //bellmanford matrix
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "BellmanFordAlgorithmMatrix.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//
//    cout<<"bellmanford z macierzą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=400; size<=1000; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            graph->randomGraph(size, densities[densityID]);
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                shortestPathAlgorithm->start = i+1;
//                shortestPathAlgorithm->update();
//                time->start();
//                shortestPathAlgorithm->startBellmanFordWithMatrix();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu bellmana forda na macierzy"<<endl;
//
//
//
//    //bellmanford list
//    //tworzenie nazwy pliku odpowiadającej typowi algorytmu oraz typowi danych na jakich algorytm operuje
//    name = "BellmanFordAlgorithmList.csv";
//    file.open(name, ios::app);  //otwieranie pliku
//
//    cout<<"bellmanFord z listą"<<endl;
//    for(int densityID=0; densityID<3; densityID++){
//        cout<<"\t"<<densities[densityID]<<endl;
//        for(int size=400; size<=1000; size+=100){
//            cout<<"\t\t"<<size<<endl;
//            graph->randomGraph(size, densities[densityID]);
//            for(int i=0; i<50; i++) {
//                cout<<"\t\t\t"<<i<<endl;
//                shortestPathAlgorithm->start = i+1;
//                shortestPathAlgorithm->update();
//                time->start();
//                shortestPathAlgorithm->startBellmanFordWithList();
//                algorithmTime = time->getTimeMiliseconds();
//                file << algorithmTime << ";";
//
//            }
//            file << endl;
//        }
//    }
//
//    file.close();
//    cout<<"Koniec algorytmu bellmanford na listą"<<endl;
//
//    delete shortestPathAlgorithm;
//
//    delete graph;
//delete time;
//}
//
//AutoTests::~AutoTests() {
//
//}








//
// Created by radom on 08.05.2024.
//

#include <fstream>
#include "AutoTests.h"
#include "Time.h"
#include "../graph/Graph.h"
#include "../algorithms/MSTalgorithms.h"
#include "../algorithms/ShortestPathAlgorithm.h"

//todo autotests

//prim list 25 400=1  500=3.6  1000=56
//prim list 50 400=3
//prim list 99 400=6  600=32  800= 95 1000=233   400, 550, 700, 850, 1000, 1150, 1300
//prim matrix 25 100=0.65
//prim matrix 50 220=6
//prim matrix 99 220=17
//        100 - 700

//kruskal list 25 400=1
//kruskal list 50 400=5
//kruskal list 99 400=15
//kruskal matrix 25  220=1
//kruskal matrix 50 220=3
//kruskal matrix 99 220=8
//        100 - 700

//dijkstra list 25 2000 = 0.735
//dijkstra list 50 2000 = 1.415
//dijkstra list 99 2000 = 2.818
//dijkstra matrix 25 600 = 1
//dijkstra matrix 50 600=2
//dijkstra matrix 99 600=5
//400, 500, 600, 700, 800, 900, 1000

//bellmanford list 25 2000 = 0.039  500 wierzcchołków = 3ms
//bellmanford list 50 2000 = 0.073
//bellmanford list 99 2000 = 0.106
//bellmanford matrix 25 600 = 2
//bellmanford matrix 50 600 = 2
//bellmanford matrix 99 600=7
//400, 500, 600, 700, 800, 900, 1000


//32323ms gemeruje sie 99% graf 1500 wierzchołków
//69446ms gemeruje sie 99% graf 2000 wierzchołków

//7 reprezentatywnych wielkosci
// Dla każdego zestawu: reprezentacja,
// liczba wierzchołków i gęstość należy
// wygenerować serię losowych instancji (np. 50
AutoTests::AutoTests(){//todo do tworzenia grafu dodac mozliowsc zwiekszenia ilosci krawedzi w grafie np z 25 na 50
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
                graph->randomGraph(size, densities[densityID]);


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
        for(int size=400; size<=1000; size+=100){
            cout<<"\t\trozmiar "<<size<<endl;
            graph->randomGraph(size, densities[densityID]);
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
