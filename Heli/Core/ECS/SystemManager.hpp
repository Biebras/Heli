#pragma once

class SystemManager
{
    public:
        // Singleton
        static SystemManager& GetInstance()
        {
            static SystemManager instance;
            return instance;
        }
        void Update();

    private:
        // Singleton stuff
        SystemManager() = default;
        ~SystemManager() = default;
        SystemManager(const SystemManager&) = delete;
        SystemManager& operator=(const SystemManager&) = delete;
};


