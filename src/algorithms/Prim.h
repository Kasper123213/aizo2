//
// Created by radom on 23.05.2024.
//

#ifndef AIZO2_PRIM_H
#define AIZO2_PRIM_H


#include "../structures/Table.h"

class Prim {

public:
    Table **matrix; //wierzchołek -> wagi kolejnych krawędzi //waga ujemna jesli krawedz idzie do, dodatnia jesli wychodzi
    Table ***list;//wierzchołek -> następnicy -> wagi następników

    Prim (Table **pTable, Table ***pTable1);
    ~Prim();

    void startWithMatrix();
};


#endif //AIZO2_PRIM_H
