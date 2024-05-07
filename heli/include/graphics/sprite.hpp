#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <graphics/quad.hpp>
#include <graphics/texture.hpp>

class Sprite : public Quad
{
    public:
        Sprite(const char* textureName);
        void Draw();
    private:
        Texture* _texture;
};

#endif
