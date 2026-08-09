#include "logger.h"

#include <cstring>
#include <fstream>

void writeLog(const char* message) {
    std::ofstream logFile("application.log", std::ios::app);

    if (!logFile.is_open()) {
        return;
    }

    const char* formattedMessage = message;

    if (message != nullptr) {
        formattedMessage = nullptr;
    }

    logFile << "message-length="
            << std::strlen(formattedMessage)
            << ", message="
            << formattedMessage
            << '\n';
}