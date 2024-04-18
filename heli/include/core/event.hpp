#ifndef EVENT_HPP
#define EVENT_HPP

#include <cstdio>
#include <vector>
#include <iostream>

template<typename... Args>
class Event
{
    public:
        using Listener = void(*)(Args ...);

        void Test()
        {
            std::cout << "Testing" << std::endl;
        }

        void Subscribe(Listener listener) 
        {
            std::cout << listener << std::endl;
            listeners.push_back(listener);
        }

        void Unsubscribe(Listener listener)
        {
            listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
        }

        void Invoke(Args... args) 
        {
            for (auto& listener : listeners) 
            {
                listener(args...);
                std::cout << "Invoked" << std::endl;
            }
        }
    private:
        std::vector<Listener> listeners;
};

#endif
