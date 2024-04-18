#shader vertex
#version 410 core
layout (location = 0) in vec3 aPos;

uniform mat4 MVP;

void main()
{
    gl_Position = MVP * vec4(aPos, 1.0f);
}

#shader fragment
#version 410 core

out vec4 result;

void main()
{
    result = vec4(1.0);
}
