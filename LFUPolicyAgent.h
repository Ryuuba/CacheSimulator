#ifndef LFU_POLICY_AGENT_H
#define LFU_POLICY_AGENT_H

#include "PolicyAgent.h"

class LFUPolicyAgent : public PolicyAgent {
private:
    unsigned replacementPolicy(unsigned slot = 0){return slot;}
public:
    LFUPolicyAgent(){}
    ~LFUPolicyAgent(){}
};

#endif