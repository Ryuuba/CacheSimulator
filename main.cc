#include "Simulator.h"
#include <cstdlib>

int main(int argc, char* argv[]) {
    unsigned seed = std::atoi(argv[2]);
    Simulator sim(argv[1], seed);
    sim.run();
    sim.computeStatistics();
    return 0;
}