#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account(std::string accountNumber, double initialBalance);

    bool deposit(double amount);
    bool withdraw(double amount);

    [[nodiscard]] double getBalance() const;
    [[nodiscard]] const std::string& getAccountNumber() const;

private:
    static bool isValidAmount(double amount);

    std::string accountNumber_;
    double balance_;
};

#endif