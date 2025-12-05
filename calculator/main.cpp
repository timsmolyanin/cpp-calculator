#include <iostream>
#include "calculator.h"

int main() {
    bool ok = RunCalculatorCycle();

    if (!ok) {
        std::cerr << "Calculator stopped due to an error." << std::endl;
        return 1;
    }

    std::cout << "Calculator finished successfully." << std::endl;
    return 0;
}