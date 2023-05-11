#pragma once

#include <iostream>
#include <string>
#include <cstdarg>

namespace Heli 
{
    class LogManager 
    {
        public:
            static void LogWarning(const char* format, ...);
            static void LogError(const char* format, ...);

        private:
            static void Log(const char* colorCode, const char* prefix, const char* format, va_list args);
    };

    void LogManager::Log(const char* colorCode, const char* prefix, const char* format, va_list args) 
    {
        std::cout << colorCode << prefix;
        vprintf(format, args);
        std::cout << "\033[0m" << std::endl;
    }

    void LogManager::LogWarning(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        Log("\033[33m", "Warning: ", format, args);
        va_end(args);
    }

    void LogManager::LogError(const char* format, ...) 
    {
        va_list args;
        va_start(args, format);
        Log("\033[31m", "Error: ", format, args);
        va_end(args);
    }
}