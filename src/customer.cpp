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

bool exportCustomerName(
    const Customer& customer,
    char* destination,
    std::size_t destinationSize
) {
    if (destination == nullptr || destinationSize == 0) {
        return false;
    }

    const std::string& name = customer.getName();

    if (name.length() >= destinationSize) {
        destination[0] = '\0';
        return false;
    }

    std::memcpy(
        destination,
        name.c_str(),
        name.length() + 1
    );

    return true;
}