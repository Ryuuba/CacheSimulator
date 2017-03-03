#include "ProgramCounterManager.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    unsigned seed = std::atoi(argv[1]);
    cout << seed << endl;
    std::minstd_rand0 generator(seed);
    ProgramCounterManager pcManager;
    do
        cout << "Program counter: " << pcManager.getPC(generator) << endl;
    while (pcManager.getInstructionNumber());
    return 0;
}