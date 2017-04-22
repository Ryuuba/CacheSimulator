#ifndef FIFO_POLICY_AGENT_H
#define FIFO_POLICY_AGENT_H

#include "PolicyAgent.h"

class FIFOPolicyAgent : public PolicyAgent {
private:
    unsigned miss;
    unsigned replacementPolicy(unsigned slot = 0) {
        //The number of misses modulus the capacity equals the slot to be 
        //overwritten
        //If the slot equals the capacity, then a miss occurs.
        unsigned fifo_slot = (slot == capacity) ? (miss++%capacity) : miss%capacity;
        std::cout << "FIFO slot :" << fifo_slot << std::endl;
        return fifo_slot;
    }
public:
    FIFOPolicyAgent(unsigned capacity){ 
        this->capacity = capacity;
        miss = 0;
        }
    ~FIFOPolicyAgent(){}
};

#endif