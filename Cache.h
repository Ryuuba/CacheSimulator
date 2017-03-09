#ifndef CACHE_H
#define CACHE_H
#include <iostream>

class Cache {
protected:
    unsigned log2_slotSize; //log_2 of the capacity of the slot in words
    unsigned log2_capacity; //log_2 of the number of slots in the Cache
    const unsigned slotSize;
    const unsigned capacity;
public:
    Cache(unsigned slotSize, unsigned capacity) : slotSize(slotSize), capacity(capacity) {
        log2_slotSize = 0;
        log2_capacity = 0;
    }
    Cache(const Cache& cache) : slotSize(cache.slotSize), capacity(cache.capacity) {
        log2_slotSize = 0;
        log2_capacity = 0;
    }
    virtual ~Cache(){}
    /** @brief This method indicates whether a word is in the cache or not */
    virtual bool fetchWord(unsigned) = 0;
};

#endif