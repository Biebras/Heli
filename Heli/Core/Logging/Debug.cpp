#include "Debug.hpp"

namespace Heli
{
    void LogManager::LogBase(const char* colorCode, const char* prefix, const char* format, va_list args) 
    {
        // Get the current time
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);

        // Print the color code 
        std::cout << colorCode;

        // Print the hour, minute, and second
        std::cout << "[" << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << "]";

        // Print the prefix
        std::cout << prefix;

        // Print the formatted message
        vprintf(format, args);

        // Reset the color and print a newline
        std::cout << "\033[0m" << std::endl;
    }

    void LogManager::Log(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        LogBase("\033[37m", "[LOG]: ", format, args);
        va_end(args);
    }

    void LogManager::LogWarning(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        LogBase("\033[33m", "[WARNING]: ", format, args);
        va_end(args);
    }

    void LogManager::LogError(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        LogBase("\033[31m", "[ERROR]: ", format, args);
        va_end(args);
    }
}