#include "fee_calculator.h"

double calculateAverageTransactionFee(double totalFeeAmount, int transactionCount) {
    if (transactionCount <= 0) {
        return 0.0;
    }

    return totalFeeAmount / static_cast<double>(transactionCount);
}
