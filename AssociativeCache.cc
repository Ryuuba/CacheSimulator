#include "AssociativeCache.h"

AssociativeCache::AssociativeCache(
    unsigned log2_capacity,
    unsigned log2_slotSize,
    Policy policy,
    std::ranlux48 *rng) : Cache(std::pow(2, log2_slotSize), std::pow(2, log2_capacity)),
                     label(std::pow(2, log2_capacity), 0) //constructs a vector of size capacity with zeroes
{
    this->log2_capacity = log2_capacity;
    this->log2_slotSize = log2_slotSize;
    switch (policy)
    {
    case Policy::LFU:
        agent = new LFUPolicyAgent(capacity);
        break;
    case Policy::LRU:
        agent = new LRUPolicyAgent(capacity);
        break;
    case Policy::FIFO:
        agent = new FIFOPolicyAgent(capacity);
        break;
    default:
        agent = new RandomPolicyAgent(capacity, rng);
    }
}

AssociativeCache::~AssociativeCache()
{
    if (agent)
        delete agent;
}

bool AssociativeCache::fetchWord(unsigned address)
{
    //Assume the word is in the cache
    bool result = true;
    //Computes the block label
    unsigned blockLabel = address / slotSize;
    //Look up the label in the vector. This method returns an iterator pointing
    //to the end of the vector when the label is not in the cache
    auto it = std::find(label.begin(), label.end(), blockLabel);
    //Computes the address of the slot keeping the requested word
    unsigned slot = std::distance(label.begin(), it);
    //Updates the freshness of a slot when it is in the cache and gets the
    //slot to be replaced
    unsigned oldestSlot = agent->replacementPolicy(slot);
    //If the word is not in the cache, then overwrite the oldest slot in the
    //cache by the one whose label is blockLabel. In this case, the result is
    //false due to the fact that the block is not in the cache.
    if (it == label.end())
    {
        label[oldestSlot] = blockLabel;
        result = false;
    }
    print();
    return result;
}

void AssociativeCache::print()
{
    std::cout << "Labels: ";
    for (auto &lbl : label)
        std::cout << lbl << ' ';
    std::cout << std::endl;
}