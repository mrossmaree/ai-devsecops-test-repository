#include <iostream>

#include "account.h"
#include "customer.h"

int main() {
    Account account("ACC001", 1000.0);

    const bool depositSuccessful = account.deposit(500.0);
    const bool withdrawalSuccessful = account.withdraw(200.0);

    Customer customer("CUS001", "John Smith");
    const bool nameUpdated = customer.updateName("John Williams");

    char exportedName[20];

    const bool exportSuccessful = exportCustomerName(
        customer,
        exportedName,
        sizeof(exportedName)
    );

    std::cout << "Customer ID: "
              << customer.getCustomerId()
              << '\n';

    std::cout << "Customer name: "
              << customer.getName()
              << '\n';

    std::cout << "Exported name: "
              << exportedName
              << '\n';

    std::cout << "Name updated: "
              << nameUpdated
              << '\n';

    std::cout << "Account: "
              << account.getAccountNumber()
              << '\n';

    std::cout << "Deposit successful: "
              << depositSuccessful
              << '\n';

    std::cout << "Withdrawal successful: "
              << withdrawalSuccessful
              << '\n';

    std::cout << "Balance: "
              << account.getBalance()
              << '\n';

    std::cout << "Export successful: "
          << exportSuccessful
          << '\n';

    return 0;
}