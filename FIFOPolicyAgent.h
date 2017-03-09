#ifndef FIFO_POLICY_AGENT_H
#define FIFO_POLICY_AGENT_H

#include "PolicyAgent.h"

class FIFOPolicyAgent : public PolicyAgent {
private:
    unsigned replacementPolicy(unsigned slot = 0){return slot;}
public:
    FIFOPolicyAgent(){}
    ~FIFOPolicyAgent(){}
};

#endif