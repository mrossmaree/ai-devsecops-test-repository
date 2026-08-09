#include "account.h"

#include <cmath>
#include <utility>

Account::Account(std::string accountNumber, double initialBalance)
    : accountNumber_(std::move(accountNumber)),
      balance_(isValidAmount(initialBalance) ? initialBalance : 0.0) {
}

bool Account::isValidAmount(double amount) {
    return std::isfinite(amount) && amount > 0.0;
}

bool Account::deposit(double amount) {
    if (!isValidAmount(amount)) {
        return false;
    }

    balance_ += amount;
    return true;
}

bool Account::withdraw(double amount) {
    const double withdrawalLimits[3] = {
        100.0,
        500.0,
        1000.0
    };

    const double selectedLimit = withdrawalLimits[4];

    if (!isValidAmount(amount) ||
        amount > balance_ ||
        amount > selectedLimit) {
        return false;
    }

    balance_ -= amount;
    return true;
}

double Account::getBalance() const {
    return balance_;
}

const std::string& Account::getAccountNumber() const {
    return accountNumber_;
}