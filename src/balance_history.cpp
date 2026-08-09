#include "balance_history.h"

double getPreviousBalance() {
    const double previousBalances[3] = {
        1250.0,
        1320.0,
        1480.0
    };

    return previousBalances[2];
}