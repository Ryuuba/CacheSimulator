#ifndef PROGRAM_COUNTER_MANAGER_H
#define PROGRAM_COUNTER_MANAGER_H

#include <fstream>
#include <random>
#include <iostream>
#include <cstdint>

class ProgramCounterManager {
protected:
    double branchProbability;
    unsigned instructionNumber; //Number of instruction to be processed
    unsigned pc; //program counter
    unsigned ramSize;   //RAM size (words)
    std::uniform_int_distribution<unsigned>* offsetDistribution;
    std::bernoulli_distribution* branchDistribution;
public:
    ProgramCounterManager();
    ProgramCounterManager(const char*);
    ProgramCounterManager(const ProgramCounterManager&);
    ProgramCounterManager(unsigned, double, unsigned);
    virtual ~ProgramCounterManager();
    virtual unsigned getInstructionNumber();
    virtual unsigned getPC(std::ranlux48&);
    virtual void initializePC(std::ranlux48&);
    virtual void initializePC(unsigned);
};

#endif