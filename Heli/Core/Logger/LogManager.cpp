#include "LogManager.hpp"

namespace Heli
{
    void LogManager::LogBase(const char* colorCode, const char* prefix, const char* format, va_list args) 
    {
        std::cout << colorCode << prefix;
        vprintf(format, args);
        std::cout << "\033[0m" << std::endl;
    }

    void LogManager::Log(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        LogBase("\033[37m", "Log: ", format, args);
        va_end(args);
    }

    void LogManager::LogWarning(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        LogBase("\033[33m", "Warning: ", format, args);
        va_end(args);
    }

    void LogManager::LogError(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        LogBase("\033[31m", "Error: ", format, args);
        va_end(args);
    }
}