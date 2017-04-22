#ifndef LFU_POLICY_AGENT_H
#define LFU_POLICY_AGENT_H

#include "PolicyAgent.h"

class LFUPolicyAgent : public PolicyAgent {
private:
    std::vector<unsigned> slot_counter;
    unsigned replacementPolicy(unsigned slot = 0){
        auto it = std::min_element(slot_counter.begin(), slot_counter.end());
        unsigned lfu_slot = std::distance(slot_counter.begin(), it);
        if (slot == capacity)
            slot_counter[lfu_slot] = 0;
        else
            slot_counter[slot]++;
        std::cout << "Slot counter: ";
        for (auto& counter : slot_counter)
            std::cout << counter << " ";
        std::cout << std::endl;
        return lfu_slot;
    }
public:
    LFUPolicyAgent(unsigned capacity) : slot_counter(capacity, 0) {
        this->capacity = capacity;
    }
    ~LFUPolicyAgent(){}
};

#endif