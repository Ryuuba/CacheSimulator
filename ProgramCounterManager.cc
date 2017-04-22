#include "ProgramCounterManager.h"

ProgramCounterManager::ProgramCounterManager() {
    instructionNumber = 10;
    branchProbability = 0.05;
    ramSize = 1024;
    offsetDistribution = new std::uniform_int_distribution<unsigned>(0, ramSize-1);
    branchDistribution = new std::bernoulli_distribution(branchProbability);
}

ProgramCounterManager::ProgramCounterManager(const char* filename) {
    std::ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> instructionNumber
            >> branchProbability
            >> ramSize;
        offsetDistribution = new std::uniform_int_distribution<unsigned>(0, ramSize-1);
        branchDistribution = new std::bernoulli_distribution(branchProbability);
    }
    else
        std::cerr << "File: " << filename <<" couldn't be opened" << std::endl;
}

ProgramCounterManager::ProgramCounterManager(const ProgramCounterManager& pcm) :
branchProbability(pcm.branchProbability),
instructionNumber(pcm.instructionNumber),
ramSize(pcm.ramSize)
{
    offsetDistribution = new std::uniform_int_distribution<unsigned>(0, ramSize-1);
    branchDistribution = new std::bernoulli_distribution(branchProbability);
}

ProgramCounterManager::ProgramCounterManager(
    unsigned instructionNumber, 
    double branchProbability, 
    unsigned ramSize
)
{
    this->instructionNumber = instructionNumber;
    this->branchProbability = branchProbability;
    this->ramSize = ramSize;
    offsetDistribution = new std::uniform_int_distribution<unsigned>(0, ramSize-1);
    branchDistribution = new std::bernoulli_distribution(branchProbability);
}

ProgramCounterManager::~ProgramCounterManager() {
    if (offsetDistribution)
        delete offsetDistribution;
    if (branchDistribution)
        delete branchDistribution;
}

unsigned ProgramCounterManager::getPC(std::ranlux48& rng) {
    bool branch = (*branchDistribution)(rng);
    if (branch)
        pc = (*offsetDistribution)(rng);
    else
        pc++;
    instructionNumber--;
    return pc;
}

void ProgramCounterManager::initializePC(std::ranlux48& rng) {
    pc = (*offsetDistribution)(rng);
}

void ProgramCounterManager::initializePC(unsigned address) {
    pc = address;
}

unsigned ProgramCounterManager::getInstructionNumber() {
    return instructionNumber;
}