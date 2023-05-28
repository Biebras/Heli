/// @file ClassTypeId.hpp
/// @brief This script was taken from the following link: 
/// https://github.com/miguelmartin75/anax/blob/master/include/anax/detail/ClassTypeId.hpp

#pragma once

#include <atomic>

namespace Heli
{
    /// @brief Define TypeId as std::size_t
    typedef std::size_t TypeId;

    /// @brief Define unsigned type macro which is -1
    #define UNDEFINED_TYPE static_cast<Heli::TypeId>(-1)

    /// @brief Class template for generating unique type IDs
    template <typename TBase>
    class ClassTypeId
    {
        public:
            /// @brief Static function template for getting the unique type ID of a given type
            /// @tparam T The type for which to get the unique ID
            template <typename T>
            static TypeId GetTypeId()
            {
                // Assign a unique ID to the given type by incrementing the nextTypeId counter
                static const TypeId id = nextTypeId++;
                return id;
            }

        private:
            /// @brief Atomic counter for generating unique type IDs
            static std::atomic<TypeId> nextTypeId;
    };
    
    /// @brief Initialize the nextTypeId counter to 0
    template <typename TBase>
    std::atomic<TypeId> ClassTypeId<TBase>::nextTypeId{0};

    /// @brief Function template for getting the unique type ID of a given type
    /// @tparam T The type for which to get the unique ID
    template <class T>
    TypeId GetTypeId()
    {
        return ClassTypeId<void>::GetTypeId<T>();
    }
}
