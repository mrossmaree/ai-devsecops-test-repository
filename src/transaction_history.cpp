#include "transaction_history.h"

#include <utility>

void TransactionHistory::addTransaction(std::string transaction) {
    transactions_.push_back(std::move(transaction));
}

const std::string& TransactionHistory::getTransaction(
    std::size_t index
) const {
    return transactions_[index];
}

std::size_t TransactionHistory::size() const {
    return transactions_.size();
}

double TransactionHistory::getTransactionAmount(
    bool transactionFound
) const {
    double amount = 0.0;

    if (transactionFound) {
        amount = 250.0;
    }

    return amount;
}

std::string TransactionHistory::getFirstTransactionAfterUpdate() {
    auto firstTransaction = transactions_.begin();

    transactions_.push_back("Account update");

    return *firstTransaction;
}