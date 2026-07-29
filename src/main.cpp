#include <iostream>

#include "account.h"
#include "customer.h"

int main() {
    Account account("ACC001", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);

    Customer customer("CUS001", "John Smith");

    std::cout << "Customer: " << customer.getName() << '\n';
    std::cout << "Account: " << account.getAccountNumber() << '\n';
    std::cout << "Balance: " << account.getBalance() << '\n';

    return 0;
}