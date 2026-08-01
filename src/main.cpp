#include <iostream>

#include "account.h"
#include "customer.h"
#include "logger.h"
#include "transaction_history.h"

int main() {
    Account account("ACC001", 1000.0);

    const bool depositSuccessful = account.deposit(500.0);
    const bool withdrawalSuccessful = account.withdraw(200.0);

    TransactionHistory history;
    history.addTransaction("Deposit: 500.00");
    history.addTransaction("Withdrawal: 200.00");

    Customer customer("CUS001", "John Smith");
    const bool nameUpdated = customer.updateName("John Williams");

    char exportedName[20];

    const bool exportSuccessful = exportCustomerName(
        customer,
        exportedName,
        sizeof(exportedName)
    );

    const char* logMessage = nullptr;
    if (exportSuccessful) {
        logMessage = "Customer export completed";
    }
    writeLog(logMessage);

    const std::string& latestTransaction = history.getTransaction(2);

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

    std::cout << "Latest transaction: "
              << latestTransaction
              << '\n';

    return 0;
}