#ifndef RANDOM_POLICY_AGENT_H
#define RANDOM_POLICY_AGENT_H

#include "PolicyAgent.h"

class RandomPolicyAgent : public PolicyAgent {
private:
    unsigned replacementPolicy(unsigned slot = 0){return slot;}
public:
    RandomPolicyAgent(){}
    ~RandomPolicyAgent(){}
};

#endif