#include "Simulator.h"

Simulator::Simulator(const char* filename, unsigned seed) :
seed(seed),
rng(seed)
{
    std::ifstream ifs(filename);
    unsigned instructionNumber, ramSize, capacity, slotSize, policy_id;
    double branchProbability;
    if (ifs.is_open()) {
        ifs >> capacity
            >> slotSize
            >> policy_id //(LRU = 1, LFU = 2, FIFO = 3, RANDOM = 4)
            >> instructionNumber
            >> branchProbability
            >> ramSize
            >> hitTime
            >> missTime;
        Policy policy = static_cast<Policy>(policy_id);
        cache = new AssociativeCache(capacity, slotSize, policy, &rng);
        pcManager = new ProgramCounterManager(instructionNumber, branchProbability, ramSize);
        hit = 0;
        miss = 0;
    }
    else
        std::cerr << "File: " << filename << " couldn't be opened" << std::endl;
}

Simulator::~Simulator() {
    if (cache)
        delete cache;
    if (pcManager)
        delete pcManager;
}

void Simulator::run() {
    pcManager->initializePC(rng);
    bool event;
    do {
        pc = pcManager->getPC(rng);
        std::cout << "Program counter: " << pc << std::endl;
        event = cache->fetchWord(pc);
        if (event) {
            std::cout << "Event: hit" << std::endl;
            hit++;
        }
        else {
            std::cout << "Event: miss" << std::endl;
            miss++;
        }

    } while (pcManager->getInstructionNumber());
}

void Simulator::computeStatistics() {
    std::cout << "Hits: " << hit << '\n' << "Miss: " << miss << std::endl;
    std::cout << "Hit ratio: " << double(hit)/(hit+miss) << std::endl;
    //TODO Compute the effective access time considering a delayed load policy
    //in order to make easy computing this metric
}