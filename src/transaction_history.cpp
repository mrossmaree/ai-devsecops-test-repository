#include "transaction_history.h"

#include <utility>

void TransactionHistory::addTransaction(std::string transaction) {
    transactions_.push_back(std::move(transaction));
}

const std::string& TransactionHistory::getTransaction(std::size_t index) const {
    return transactions_[index];
}

std::size_t TransactionHistory::size() const {
    return transactions_.size();
}
