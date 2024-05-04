#shader vertex
#version 410 core
layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 UV;

uniform mat4 MVP;

out vec2 uv;

void main()
{
    gl_Position = MVP * vec4(Pos, 1.0f);
    uv = UV;
}

#shader fragment
#version 410 core

uniform sampler2D MainTexture;

in vec2 uv;

out vec4 result;

void main()
{
    result = texture(MainTexture, uv); 
}
