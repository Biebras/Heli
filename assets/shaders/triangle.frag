#version 410 core

in vec3 ourPosition;

out vec4 fragmentColor;

void main()
{
    fragmentColor = vec4(ourPosition, 1.0);
}
