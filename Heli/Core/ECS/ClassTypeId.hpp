// This script was taken from the following link: 
// https://github.com/miguelmartin75/anax/blob/master/include/anax/detail/ClassTypeId.hpp

#pragma once

#include <atomic>

namespace Heli
{
    typedef std::size_t TypeId;

    template <typename TBase>
    class ClassTypeId
    {
        public:

            template <typename T>
            static TypeId GetTypeId()
            {
                static const TypeId id = nextTypeId++;
                return id;
            }

        private:
            static std::atomic<TypeId> nextTypeId;
    };
    
    template <typename TBase>
    std::atomic<TypeId> ClassTypeId<TBase>::nextTypeId{0};

    template <class T>
    TypeId GetTypeID()
    {
        return ClassTypeId<void>::GetTypeId<T>();
    }
}
