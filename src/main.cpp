#include <iostream>

#include "account.h"
#include "balance_history.h"
#include "customer.h"
#include "fee_calculator.h"
#include "logger.h"
#include "receipt_processor.h"
#include "statement_exporter.h"
#include "transaction_history.h"
#include "transaction_importer.h"

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

    const std::string& latestTransaction =
        history.getTransaction(2);

    const double transactionAmount =
        history.getTransactionAmount(false);

    const double previousBalance =
        getPreviousBalance();

    const double averageFee =
        calculateAverageTransactionFee(7.50, 0);

    const bool receiptProcessed =
        processTransactionReceipt("RCPT-1001", 12.50);

    const bool statementExported =
        exportAccountStatement(
            "account_statement.txt",
            account.getAccountNumber().c_str(),
            account.getBalance()
        );

    const std::string displayName =
        customer.createDisplayName();

    const std::string firstTransaction = history.getFirstTransactionAfterUpdate();

    const bool transactionImported = importTransaction(
        "ACCOUNT-123456789",
        "Monthly transfer",
        5);

    std::cout << "Customer ID: "
              << customer.getCustomerId()
              << '\n';

    std::cout << "Customer name: "
              << customer.getName()
              << '\n';

    std::cout << "Display name: "
              << displayName
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

    std::cout << "Transaction amount: "
              << transactionAmount
              << '\n';

    std::cout << "Previous balance: "
              << previousBalance
              << '\n';

    std::cout << "Average transaction fee: "
              << averageFee
              << '\n';

    std::cout << "Receipt processed: "
              << receiptProcessed
              << '\n';

    std::cout << "Statement export successful: "
              << statementExported
              << '\n';
    
    std::cout << "First transaction: "
          << firstTransaction
          << '\n';

    std::cout << "Transaction imported: "
          << transactionImported
          << '\n';

    return 0;
}