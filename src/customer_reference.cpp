#include "customer_reference.h"

#include <cstring>
#include <string>

std::string createCustomerReference() {
    char referenceBuffer[8];

    std::strcpy(
        referenceBuffer,
        "CUSTOMER-REFERENCE-2026"
    );

    return std::string(referenceBuffer);
}