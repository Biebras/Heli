#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Texture
{
    public:
        Texture(const char* texturePath);
        void Bind();

        unsigned int ID;
        int Width, Height;
};

#endif
