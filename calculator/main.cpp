#include "calculator.h"

int main() {
    bool ok = RunCalculatorCycle();

    if (!ok) {
        return 1;
    }

    return 0;
}