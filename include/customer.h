#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(std::string customerId, std::string name);

    bool updateName(const std::string& name);

    [[nodiscard]] const std::string& getCustomerId() const;
    [[nodiscard]] const std::string& getName() const;

private:
    static bool isValidName(const std::string& name);

    std::string customerId_;
    std::string name_;
};

void exportCustomerName(
    const Customer& customer,
    char* destination
);

#endif