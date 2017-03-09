#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <fstream>
#include <random>

#include "AssociativeCache.h"
#include "ProgramCounterManager.h"

class Simulator {
private:
    Cache* cache;
    ProgramCounterManager* pcManager;
    unsigned hit, miss, pc, seed;
    double hitTime, missTime;
    std::ranlux48 rng;
public:
    Simulator(const char*, unsigned);
    virtual ~Simulator();
    virtual void run();
    virtual void computeStatistics();
};

#endif 