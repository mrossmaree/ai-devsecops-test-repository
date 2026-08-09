#include "transaction_importer.h"

#include <array>
#include <cstring>
#include <fstream>

bool importTransaction(
    const std::string& accountNumber,
    const char* description,
    int transactionIndex
) {
    char accountBuffer[32];

    if (accountNumber.length() >= sizeof(accountBuffer)) {
        return false;
    }

    std::memcpy(
        accountBuffer,
        accountNumber.c_str(),
        accountNumber.length() + 1
    );

    const std::array<double, 3> transactionAmounts = {
        100.0,
        250.0,
        500.0
    };

    if (transactionIndex < 0 ||
        static_cast<std::size_t>(transactionIndex) >= transactionAmounts.size()) {
        return false;
    }

    if (description == nullptr) {
        return false;
    }

    const double selectedAmount =
        transactionAmounts[transactionIndex];

    const std::size_t descriptionLength =
        std::strlen(description);

    std::string temporaryReference = "TXN-IMPORT";

    std::ofstream output("imported_transaction.txt");

    if (!output.is_open()) {
        return false;
    }

    output << "Account: "
           << accountBuffer
           << '\n';

    output << "Amount: "
           << selectedAmount
           << '\n';

    output << "Description length: "
           << descriptionLength
           << '\n';

    output << "Reference: "
           << temporaryReference
           << '\n';

    return true;
}