#ifndef EVENT_HPP
#define EVENT_HPP

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
            printf("Id: %d\n", listenerId);
            return listenerId;
        }

        void Unsubscribe(int listenerId)
        {
            printf("Id: %d\n", listenerId);
            printf("Listener: %p\n", &listeners[listenerId]);
            listeners.erase(listenerId);
        }

        void Invoke(Args... args) 
        {
            for (auto& listener : listeners) 
            {
                listener.second(args...);
            }
        }
    private:
        int listenerId = 0;
        std::unordered_map<int, Listener> listeners;
};

#endif
