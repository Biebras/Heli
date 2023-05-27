#pragma once

#include "../ECS/Component.hpp"

namespace Heli
{
    struct SpriteComponent : public Component 
    {
        int textureId;
        int width;
        int height;
    };
}