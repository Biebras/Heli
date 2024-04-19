#ifndef EVENT_HPP
#define EVENT_HPP

#include <cstdio>
#include <unordered_map>
#include <functional>

#define MethodSubscriber(fn) [this](auto... args){this->fn(args...);}

template<typename... Args>
class Event
{
    public:
        using Listener = std::function<void(Args ...)>;

        int Subscribe(const Listener &listener) 
        {
            listenerId++;
            listeners[listenerId] = listener;
            return listenerId;
        }

        void Unsubscribe(int listenerId)
        {
            listeners.erase(listenerId);
        }

        void Invoke(Args... args) 
        {
            auto tmpListeners = listeners;

            for (auto& listener : tmpListeners) 
            {
                listener.second(args...);
            }
        }
    private:
        int listenerId = 0;
        std::unordered_map<int, Listener> listeners;
};

#endif
