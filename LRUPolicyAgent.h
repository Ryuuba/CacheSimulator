#ifndef LRU_POLICY_AGENT_H
#define LRU_POLICY_AGENT_H

#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include "PolicyAgent.h"

class LRUPolicyAgent : public PolicyAgent {
private:
    //This implementation only allows 64 slots
    std::vector<uint64_t> neatLittleMatrix;
    void updateNeatLittleMatrix(unsigned);
    virtual void print();
    virtual unsigned replacementPolicy(unsigned slot = 0);
public:
    LRUPolicyAgent(unsigned);
    ~LRUPolicyAgent(){}
};

#endif