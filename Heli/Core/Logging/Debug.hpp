#pragma once

#include <iostream>
#include <string>
#include <cstdarg>
#include <ctime>

namespace Heli 
{
    class LogManager 
    {
        public:
            static void Log(const char* format, ...);
            static void LogWarning(const char* format, ...);
            static void LogError(const char* format, ...);

        private:
            static void LogBase(const char* colorCode, const char* prefix, const char* format, va_list args);
    };

    // Define macros for easier access to the log functions
    #define LOG(format, ...) LogManager::Log(format, ##__VA_ARGS__)
    #define LOG_WARNING(format, ...) LogManager::LogWarning(format, ##__VA_ARGS__)
    #define LOG_ERROR(format, ...) LogManager::LogError(format, ##__VA_ARGS__)
}