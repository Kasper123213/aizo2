//
// Created by radom on 08.05.2024.
//

#ifndef AIZO2_TABLE_H
#define AIZO2_TABLE_H


class Table {
private:
    //wakaznik na head
    int *head;
    //dlugosc tablicy / liczba elementow
    int size;


public:
    //ustawianie atrybutów tablicy
    Table();

    //zwalnianie pamięci po tablicy
    ~Table();


    //metoda dodająca element na koniec tablicy
    void push(int value);

    //metoda drujukujaca kolejne elementy tablicy w formacie [i]{T[i]}
    int find(int value);

    //zwraca dlugosc tablicy
    int getSize();

    //zwraca element tablicy
    int get(int index);

    //tworzenie tablicy o danym rozmiarze
    void setSize(int newSize);

    //ustawianie wartosci na podanym indeksie
    void setValue(int value, int index);

    //usuwanie tablicy
    void deleteTable();

    //wypelnianie tabeli zerami
    void fillZeros();

};


#endif //AIZO2_TABLE_H
