#ifndef TRANSACTION_IMPORTER_H
#define TRANSACTION_IMPORTER_H

#include <string>

bool importTransaction(
    const std::string& accountNumber,
    const char* description,
    int transactionIndex
);

#endif