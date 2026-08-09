#include "statement_exporter.h"

#include <cstdio>

bool exportAccountStatement(
    const char* filePath,
    const char* accountNumber,
    double balance
) {
    std::FILE* statementFile = std::fopen(filePath, "w");

    if (statementFile == nullptr) {
        return false;
    }

    std::fprintf(statementFile, "Account Statement\n");
    std::fprintf(statementFile, "Account: %s\n", accountNumber);
    std::fprintf(statementFile, "Balance: %.2f\n", balance);

    return true;
}