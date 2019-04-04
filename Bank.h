//
// Created by Ben Trueman on 2019-03-30.
//

#ifndef DISCRETEEVENTSIMULATOR_BANK_H
#define DISCRETEEVENTSIMULATOR_BANK_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdlib.h>
#include "Event.h"

#define SIM_LENGTH 43200 //12 hours = 43,200 seconds
#define NUM_TELLERS 6
using namespace std;

class Bank {
private:
    priority_queue<Event, vector<Event>, compareEventTime> eventQueue;
    std::queue<Event> bankQueue;
    double currentTime = 0;
    int tellersAvailable = NUM_TELLERS;

public:
    vector<double> serviceTimes;
    void addEvent(Event &event);
    void addBankCustomer(Event event);
    void runSim();
    void calcAvgServiceTime();
    void printEventInfo(const Event &event);
};


#endif //DISCRETEEVENTSIMULATOR_BANK_H