#include "logger.h"

#include <cstring>
#include <fstream>

void writeLog(const char* message) {
    std::ofstream logFile("application.log", std::ios::app);

    if (!logFile.is_open()) {
        return;
    }

    logFile << "message-length="
            << std::strlen(message)
            << ", message="
            << message
            << '\n';
}
