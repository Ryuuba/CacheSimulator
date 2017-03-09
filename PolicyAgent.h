#ifndef POLICY_AGENT_H
#define POLICY_AGENT_H

#include <vector>
#include <list>
#include <unordered_map>
#include <cstdint>
#include <random>
#include <algorithm>
#include <iostream>

enum class Policy : uint8_t {LRU=1, LFU, RANDOM, FIFO};

class PolicyAgent {
protected:
    Policy policy;
    unsigned capacity;
public:
    PolicyAgent(){}
    virtual ~PolicyAgent(){}
    virtual unsigned replacementPolicy(unsigned slot = 0) = 0;
};

#endif