#include "customer.h"
#include <cstring>

#include <algorithm>
#include <cctype>
#include <utility>

Customer::Customer(std::string customerId, std::string name)
    : customerId_(std::move(customerId)),
      name_(isValidName(name) ? std::move(name) : "Unknown") {
}

bool Customer::isValidName(const std::string& name) {
    if (name.empty() || name.length() > 100) {
        return false;
    }

    return std::any_of(
        name.begin(),
        name.end(),
        [](unsigned char c) {
            return std::isalpha(c) != 0 || c == ' ';
        });
}

bool Customer::updateName(const std::string& name) {
    if (!isValidName(name)) {
        return false;
    }

    name_ = name;
    return true;
}

const std::string& Customer::getCustomerId() const {
    return customerId_;
}

const std::string& Customer::getName() const {
    return name_;
}

void exportCustomerName(
    const Customer& customer,
    char* destination
) {
    std::strcpy(
        destination,
        customer.getName().c_str()
    );
}