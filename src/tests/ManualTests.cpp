//
// Created by radom on 08.05.2024.
//

#include "ManualTests.h"
#include "../algorithms/MSTalgorithms.h"

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
                if (problem == ManualTests::Problem::MST){
                    graph->randomGraph(vertices, density, 'U');
                }else{
                    graph->randomGraph(vertices, density, 'D');
                }

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
                    //todo Dijkstra
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
                    //todo Bellman-Ford
                }
                break;

            case 'f':
                graph->saveGraph();
        }
    }while(choice!='q');
}

//Wybór problemu
ManualTests::Problem ManualTests::choseProblem() {
    char choice = 'a';
    do{
        cout<<"Wybierz problem:"<<endl
            << "a) Wyznaczanie minimalnego drzewa rozpinającego (MST)"<<endl
            << "b) Wyznaczanie najkrótszej ścieżki w grafie"<<endl
            <<endl<<">>";
//        cin>>choice;
        cout<<endl<<endl;

        if (choice == 'a') return Problem::MST;
        else if (choice == 'b') return Problem::SHORTEST_PATH;
    }while(true);
}

//Wybór reprezentacji
ManualTests::Representation ManualTests::choseRepresentation() {
    char choice;
    do{
        cout<<"Wybierz problem:"<<endl
            << "a) Reprezentacja macierzowa (macierz incydencji),"<<endl
            << "b) Reprezentacja listowa (lista następników/poprzedników)"<<endl
            <<endl<<">>";
        cin>>choice;
        cout<<endl<<endl;

        if (choice == 'a') return Representation::MATRIX;
        else if (choice == 'b') return Representation::LIST;
    }while(true);

}

ManualTests::~ManualTests() = default;

void ManualTests::readFromFile() {
    string path;
    cout<<"Podaj ścieżkę"<<endl<<">>";
//    cin>>path; //todo odkomentowac
    cout<<endl<<endl;

    path = "C:\\Users\\radom\\OneDrive\\Pulpit\\aizo\\aizo2\\files\\opisGrafNieskierowany.txt";

    if (problem == ManualTests::Problem::MST){
        graph->readGraph(path, 'U');
    }else{
        graph->readGraph(path, 'D');
    }

    cout<<"Zakończono wczytywanie grafu."<<endl<<endl;
}


