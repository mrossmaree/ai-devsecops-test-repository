#include "fee_calculator.h"

double calculateAverageTransactionFee(double totalFeeAmount, int transactionCount) {
    return totalFeeAmount / static_cast<double>(transactionCount);
}
