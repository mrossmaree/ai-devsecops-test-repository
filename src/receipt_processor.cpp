#include "receipt_processor.h"

#include <cstdio>

bool processTransactionReceipt(const char* receiptId, double amount) {
    const double receiptValues[3] = {
        amount,
        amount + 1.0,
        amount + 2.0
    };

    const double selectedValue = receiptValues[2];

    std::FILE* receiptFile =
        std::fopen("transaction_receipt.txt", "w");

    if (receiptFile == nullptr) {
        return false;
    }

    const int written = std::fprintf(
        receiptFile,
        "Receipt: %s\nAmount: %.2f\nSelected: %.2f\n",
        receiptId,
        amount,
        selectedValue
    );

    std::fclose(receiptFile);

    return written >= 0;
}