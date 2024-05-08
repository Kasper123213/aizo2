//
// Created by radom on 08.05.2024.
//

#ifndef AIZO2_MANUALTESTS_H
#define AIZO2_MANUALTESTS_H

#include <iostream>
#include "../graph/Graph.h"

namespace std {

    class ManualTests {
    private:
        enum class Problem{
            MST, SHORTEST_PATH
        };
        enum class Representation{
            MATRIX, LIST
        };


        Problem problem;
        Representation representation;

        Graph* graph;

        Problem choseProblem(); //a MST, b najkrutsza ścieżka
        Representation choseRepresentation(); //a macierz, b lista
        void readFromFile();


    public:
        ManualTests();
        ~ManualTests();
    };

} // std

#endif //AIZO2_MANUALTESTS_H
