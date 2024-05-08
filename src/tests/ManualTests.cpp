//
// Created by radom on 08.05.2024.
//

#include "ManualTests.h"

using namespace std;

ManualTests::ManualTests(){
    graph = new Graph();

    problem = choseProblem();

    representation = choseRepresentation();

    char choice = 'a';
    do{
        cout<<"Co chcesz zrobić:"<<endl
            << "a) Wczytaj dane z pliku."<<endl
            << "b) Wygeneruj graf losowo."<<endl;

            if (representation == ManualTests::Representation::MATRIX){
                cout<< "c) Wyświetl graf macierzowo na ekranie."<<endl;
            }else{
                cout<< "c) Wyświetl graf listowo na ekranie."<<endl;
            }


            if (problem == ManualTests::Problem::MST){
                cout<< "d) Algorytm Prima"<<endl
                   << "e) Algorytm Kruskala"<<endl;
            }else{
                cout<< "d) Algorytm Dijkstry"<<endl
                    << "e) Algorytm Forda-Bellmana"<<endl;
            }

            cout<<"q) Wyjście"<<endl<<">>";
//        cin>>choice;
        cout<<endl<<endl;

        switch (choice) {
            case 'a':
                readFromFile();
                break;
            case 'b':
                //todo generowanie grafu
                break;
            case 'c':
                    //todo wyswietlanie macierzy
                    //todo wyswietlanie listy
                break;
            case 'd':
                    //todo Prim
                    //todo Dijkstra
                break;
            case 'e':
                    //todo Kruskal
                    //todo Bellman-Ford
                break;
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
    char choice = 'a';
    do{
        cout<<"Wybierz problem:"<<endl
            << "a) Reprezentacja macierzowa (macierz incydencji),"<<endl
            << "b) Reprezentacja listowa (lista następników/poprzedników)"<<endl
            <<endl<<">>";
//        cin>>choice;
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
    path = "C:\\Users\\radom\\OneDrive\\Pulpit\\aizo\\aizo2\\files\\opisGrafNieskierowany.txt";

    if (problem == ManualTests::Problem::MST){
        graph->readGraph(path, 'D');
    }else{
        graph->readGraph(path, 'U');
    }
}


