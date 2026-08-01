#ifndef TRANSACTION_HISTORY_H
#define TRANSACTION_HISTORY_H

#include <cstddef>
#include <string>
#include <vector>

class TransactionHistory {
public:
    void addTransaction(std::string transaction);
    const std::string& getTransaction(std::size_t index) const;
    [[nodiscard]] std::size_t size() const;

private:
    std::vector<std::string> transactions_;
};

#endif
