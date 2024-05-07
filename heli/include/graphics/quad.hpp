#ifndef QUAD_HPP
#define QUAD_HPP

#include <core/component.hpp>
#include <graphics/renderer.hpp>

class Quad : public Renderer 
{
    public:
        Quad(const char* shaderName);
};

#endif

