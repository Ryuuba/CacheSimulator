#ifndef ASSOCIATIVE_CACHE_H
#define ASSOCIATIVE_CACHE_H

#include <vector>
#include <cstdint>
#include <algorithm>
#include <cmath>

#include "Cache.h"
#include "LRUPolicyAgent.h"
#include "FIFOPolicyAgent.h"
#include "LFUPolicyAgent.h"
#include "RandomPolicyAgent.h"

class AssociativeCache : public Cache {
private:
    //Vector storing the labels of the blocks being in the cache
    std::vector<unsigned> label;
    //Object managing the replacement policy of a cache
    PolicyAgent* agent;
public:
    //log2_capacity, log2_slotsize, replacement policy
    AssociativeCache(unsigned, unsigned, Policy);
    //Deletes the agent if it exists
    ~AssociativeCache();
    //Fetches a word in the cache
    bool fetchWord(unsigned);
};

#endif