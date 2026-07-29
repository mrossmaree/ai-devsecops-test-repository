#include <iostream>

#include "account.h"

int main() {
    Account account("ACC001", 1000.0);

    const bool depositSuccessful = account.deposit(500.0);
    const bool withdrawalSuccessful = account.withdraw(200.0);

    std::cout << "Account: " << account.getAccountNumber() << '\n';
    std::cout << "Deposit successful: " << depositSuccessful << '\n';
    std::cout << "Withdrawal successful: " << withdrawalSuccessful << '\n';
    std::cout << "Balance: " << account.getBalance() << '\n';

    return 0;
}