//
// Created by radom on 08.05.2024.
//

#include "Table.h"
#include <iostream>

using namespace std;


Table::Table() {     //ustawianie atrybutów tablicy
    size = 0;
    head = nullptr;
}

Table::~Table() {   //zwalnianie pamięci po tablicy
    deleteTable();
}

void Table::deleteTable() {
    if (head != nullptr) {
        delete[]head;
    }
}

int Table::getSize() { return size; }


//metoda dodająca element na koniec tablicy
void Table::push(int value) {
    int *newHead = new int[size + 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice

    for (int i = 0; i < size; i++) {         //wstawianie elementow starej tablicy
        newHead[i] = head[i];
    }

    newHead[size] = value;            //dodwanie podanej valuei na koniec nowej tablicy
    size++;                                  //inkrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice

}


//metoda wyszukujaca pierwszy element o podanej valuei z tablicy i zwracajaca jego indeks,
// jesli elementu niema w tablicy, zwraca -1
int Table::find(int value) {
    for (int i = 0; i < size; i++) {                 //po kolei sprawdzamy czy i-ty element jest rowny podanej valuei
        if (head[i] == value)return i;
    }
    return -1;                                          //jesli elementu niema w tablicy zwraca -1
}

//zwracanie wartosci
int Table::get(int index) {
    return head[index];
}

//zmiana rozmiaru
void Table::setSize(int newSize) {
    deleteTable();
    size = newSize;
    head = new int[newSize];
}

//zmiana wartosci na indeksie
void Table::setValue(int index, int value) {
    head[index] = value;
}

void Table::fillZeros() {
    for(int i=0; i<size; i++){
        setValue(i, 0);
    }
}

//metoda usuwajaca element o podanym indeksie z tablicy
void Table::remove(int index) {
    if(index<0 || index>=size || size <=0){ //sprawdzanie czy podano poprawny indeks
        return;
    }
    int *newHead = new int[size - 1];   //ustawianie nowego wskaznika na nowa, wiekszą tablice
    for (int i = 0; i < index; i++) {   //wstawianie elementow starej tablicy od poczatku do podanego indeksu
        newHead[i] = head[i];
    }
    for (int i = index + 1; i < size; i++) {  //wstawianie elementow starej tablicy od podanego indeksu do konca
        newHead[i - 1] = head[i];
    }
    size--;                                  //dekrementacja zmiennej okreslajacaj dlugosc tablicy
    delete[] head;                                  //zawalnianie miejsca po poprzedniej tablicy
    head = newHead;                            //ustawianie wskaznika poczatku starej tablicy na nowa tablice

}
