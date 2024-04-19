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
            _listenerId++;
            _listeners[_listenerId] = listener;
            return _listenerId;
        }

        void Unsubscribe(int listenerId)
        {
            _listeners.erase(listenerId);
        }

        void Invoke(Args... args) 
        {
            auto tmpListeners = _listeners;

            for (auto& listener : tmpListeners) 
            {
                listener.second(args...);
            }
        }
    private:
        int _listenerId = 0;
        std::unordered_map<int, Listener> _listeners;
};

#endif
