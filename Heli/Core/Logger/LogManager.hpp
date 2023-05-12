#pragma once

#include <iostream>
#include <string>
#include <cstdarg>

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
}