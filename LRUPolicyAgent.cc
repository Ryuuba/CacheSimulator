#include "LRUPolicyAgent.h"

LRUPolicyAgent::LRUPolicyAgent(Policy policy, unsigned capacity) :
neatLittleMatrix(capacity, 0)
{
    this->capacity = capacity;
    this->policy = policy;
}


void LRUPolicyAgent::updateNeatLittleMatrix(unsigned slot) {
    //Fills the row pointed by the slot with ones
    neatLittleMatrix[slot] = std::pow(2, capacity) - 1;
    //Computes the mask to fill zeroes in columns
    unsigned mask = (std::pow(2, capacity) - 1) - std::pow(2, slot);
    //Fills with zeroes the column to be used
    for (unsigned i = 0; i < capacity; i++)
        neatLittleMatrix[i] = neatLittleMatrix[i] & mask;
}

unsigned LRUPolicyAgent::replacementPolicy(unsigned slot) {
    //computes the lru slot
    auto it = std::min_element(neatLittleMatrix.begin(), neatLittleMatrix.end());
    unsigned lruSlot = std::distance(neatLittleMatrix.begin(), it);
    //If the slot exists, then write them. Otherwise, write the lru slot
    if (slot < capacity)
        updateNeatLittleMatrix(slot);
    else
        updateNeatLittleMatrix(lruSlot);
    print();
    return lruSlot;
}

void LRUPolicyAgent::print() {
    unsigned mask = 1, bit;
    for (unsigned i = 0; i < capacity; i++) {
        for (unsigned j = 0; j < capacity; j++) {
            bit = ((neatLittleMatrix[i] & (mask << j)) == 0) ? 0 : 1;
            std::cout << bit;
        }
        std::cout << std::endl;
    }
}
