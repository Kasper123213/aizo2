//
// Created by radom on 08.05.2024.
//

#include "ManualTests.h"
#include "../algorithms/MSTalgorithms.h"
#include "../algorithms/ShortestPathAlgorithm.h"

using namespace std;

ManualTests::ManualTests(){
    graph = new Graph();

    problem = choseProblem();

    representation = choseRepresentation();

    char choice ;
    do{
        cout<<"Co chcesz zrobić:"<<endl
            << "a) Wczytaj dane z pliku."<<endl
            << "b) Wygeneruj graf losowo."<<endl
            << "c) Wyświetl graf."<<endl;



            if (problem == ManualTests::Problem::MST){
                cout<< "d) Algorytm Prima"<<endl
                   << "e) Algorytm Kruskala"<<endl;
            }else{
                cout<< "d) Algorytm Dijkstry"<<endl
                    << "e) Algorytm Forda-Bellmana"<<endl;
            }

            cout<<"f) Zapisz graf do pliku"<<endl
            <<"q) Wyjście"<<endl<<">>";
        cin>>choice;
        cout<<endl<<endl;

        switch (choice) {
            case 'a':
                readFromFile();
                break;
            case 'b':
                int vertices;
                cout<<"Podaj liczbę wierzchołków:"<<endl<<">>";
                cin>>vertices;
                cout<<endl<<endl;

                char answer;
                int density;
                cout<<"Wybierz gęstość grafu:"<<endl
                    << "a) 25%"<<endl
                    << "b) 50%"<<endl
                    << "c) 99%"<<endl<<">>";
                cin>>answer;
                cout<<endl<<endl;

                switch (answer) {
                    case 'a':
                        if(vertices<8){
                            cout<<"Graf nie będzie spójny przy takiej gęstości."<<endl<<endl;
                            return;
                        }
                        density = 25;
                        break;
                    case 'b':
                        if(vertices<4){
                            cout<<"Graf nie będzie spójny przy takiej gęstości."<<endl<<endl;
                            return;
                        }
                        density = 50;
                        break;
                    case 'c':
                        density = 99;
                        break;
                    default:
                        cout<<"Błędny wybór"<<endl<<endl;
                        return;
                }
                graph->randomGraph(vertices, density);


                break;
            case 'c':
                    graph->printMatrix();
                    graph->printList();
                    cout<<endl<<endl;
                break;
            case 'd':
                if (problem == ManualTests::Problem::MST){
                    MSTalgorithms* mstAlgorithms = new MSTalgorithms(graph);
                    if (representation == ManualTests::Representation::MATRIX) {
                        //todo mierzenie czasu
                        mstAlgorithms->startPrimWithMatrix();
                    }else{
                        mstAlgorithms->startPrimWithList();
                    }
                    delete mstAlgorithms;
                }else{
                    int start, stop;
                    cout<<"Podaj wierzchołek początkowy"<<endl<<">>";
                    cin>>start;
                    cout<<endl<<"Podaj wierzchołek końcowy"<<endl<<">>";
                    cin>>stop;
                    cout<<endl;

                    ShortestPathAlgorithm* shortestPathAlgorithm = new ShortestPathAlgorithm(graph, start, stop);
                    if (representation == ManualTests::Representation::MATRIX) {
                        //todo mierzenie czasu
                        shortestPathAlgorithm->startDijkstraWithMatrix();
                    }else{
                        shortestPathAlgorithm->startDijkstraWithList();
                    }
                    delete shortestPathAlgorithm;
                }
                break;
            case 'e':
                if (problem == ManualTests::Problem::MST){
                    MSTalgorithms* mstAlgorithms = new MSTalgorithms(graph);
                    if (representation == ManualTests::Representation::MATRIX) {
                        //todo mierzenie czasu
                        mstAlgorithms->startKruskalWithMatrix();
                    }else{
                        mstAlgorithms->startKruskalWithList();
                    }
                    delete mstAlgorithms;
                }else{
                    int start, stop;
                    cout<<"Podaj wierzchołek początkowy"<<endl<<">>";
                    cin>>start;
                    cout<<endl<<"Podaj wierzchołek końcowy"<<endl<<">>";
                    cin>>stop;
                    cout<<endl;

                    ShortestPathAlgorithm* shortestPathAlgorithm = new ShortestPathAlgorithm(graph, start, stop);
                    if (representation == ManualTests::Representation::MATRIX) {
                        //todo mierzenie czasu
                        shortestPathAlgorithm->startBellmanFordWithMatrix();
                    }else{
                        shortestPathAlgorithm->startBellmanFordWithList();
                    }
                    delete shortestPathAlgorithm;
                }
                break;

            case 'f':
                graph->saveGraph();
        }
    }while(choice!='q');
}

ManualTests::~ManualTests(){
    delete graph;
}

//Wybór problemu
ManualTests::Problem ManualTests::choseProblem() {
    char choice = 'b';
    do{
        cout<<"Wybierz problem:"<<endl
            << "a) Wyznaczanie minimalnego drzewa rozpinającego (MST)"<<endl
            << "b) Wyznaczanie najkrótszej ścieżki w grafie"<<endl
            <<endl<<">>";
//        cin>>choice;
        cout<<endl<<endl;

        if (choice == 'a') {
            graph->setType('U');
            return Problem::MST;
        }
        else if (choice == 'b'){
            graph->setType('D');
            return Problem::SHORTEST_PATH;
        }
    }while(true);
}

//Wybór reprezentacji
ManualTests::Representation ManualTests::choseRepresentation() {
    char choice;
    do{
        cout<<"Wybierz reprezentacje grafu:"<<endl
            << "a) Reprezentacja macierzowa (macierz incydencji),"<<endl
            << "b) Reprezentacja listowa (lista następników/poprzedników)"<<endl
            <<endl<<">>";
        cin>>choice;
        cout<<endl<<endl;

        if (choice == 'a') return Representation::MATRIX;
        else if (choice == 'b') return Representation::LIST;
    }while(true);

}



void ManualTests::readFromFile() {
    string path;
    cout<<"Podaj ścieżkę"<<endl<<">>";
//    cin>>path; //todo odkomentowac
    cout<<endl<<endl;

    path = "C:\\Users\\radom\\OneDrive\\Pulpit\\aizo\\aizo2\\files\\opisGrafNieskierowany.txt";

    graph->readGraph(path);

    cout<<"Zakończono wczytywanie grafu."<<endl<<endl;
}


