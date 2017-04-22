#ifndef RANDOM_POLICY_AGENT_H
#define RANDOM_POLICY_AGENT_H

#include "PolicyAgent.h"

class RandomPolicyAgent : public PolicyAgent
{
  private:
    std::ranlux48 *rng;
    std::uniform_int_distribution<unsigned> pmf;
    unsigned replacementPolicy(unsigned slot = 0)
    {
        unsigned random_slot = pmf(*rng);
        std::cout << "Random slot: " << random_slot << std::endl;
        return random_slot;
    }

  public:
    RandomPolicyAgent(unsigned capacity, std::ranlux48 *rng) : 
    pmf(0, capacity - 1)
    {
        this->capacity = capacity;
        this->rng = rng;
    }
    ~RandomPolicyAgent() {}
};

#endif