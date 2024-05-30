//
// Created by radom on 30.05.2024.
//

#ifndef AIZO2_TIME_H
#define AIZO2_TIME_H


#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono;
class Time {
private:
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point endTime;


public:
    void start();

    void stop();

    long getTimeMiliseconds();

    long getTimeSeconds();
};


#endif //AIZO2_TIME_H
