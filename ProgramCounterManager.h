#include <fstream>
#include <random>

class ProgramCounterManager {
protected:
    unsigned instructionNumber;
    unsigned pc; //program counter
    double branchProbability;
    unsigned ramSize;   //RAM size (words)
    std::bernoulli_distribution* bernoulliDistribution;
    std::uniform_int_distribution<unsigned>* discreteRandomDistribution;
public:
    ProgramCounterManager();
    ProgramCounterManager(const char*);
    virtual ~ProgramCounterManager();
    virtual unsigned getInstructionNumber();
    virtual unsigned getPC(std::minstd_rand0&);
};
