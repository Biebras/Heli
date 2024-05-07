#shader vertex
#version 410 core
layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 UV;

uniform mat4 MVP;
uniform mat4 Model;

out vec4 fragPos;

void main()
{
    vec4 pos = MVP * vec4(Pos, 1.0f);
    gl_Position = pos;
    fragPos = Model * vec4(Pos, 1.0f); 
}

#shader fragment
#version 410 core

float Grid(vec2 fragCoord, float space, float gridWidth);

uniform vec4 BaseColor;

in vec4 fragPos;

out vec4 result;

void main()
{
    float grid = Grid(vec2(fragPos.x, fragPos.y), 1, 0.01f);
    result = vec4(grid, grid, grid, 1);
}

float Grid(vec2 fragCoord, float space, float gridWidth)
{
    vec2 p  = fragCoord - vec2(.5);
    vec2 size = vec2(gridWidth);
    
    vec2 a1 = mod(p - size, space);
    vec2 a2 = mod(p + size, space);
    vec2 a = a2 - a1;
       
    float g = min(a.x, a.y);
    return clamp(g * 100, 0., 1.0);
}
