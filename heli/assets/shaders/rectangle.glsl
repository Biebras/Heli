#shader vertex
#version 410 core
layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 UV;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(Pos, 1.0f);
}

#shader fragment
#version 410 core

uniform vec4 BaseColor;

out vec4 result;

void main()
{
    result = vec4(BaseColor);
}
