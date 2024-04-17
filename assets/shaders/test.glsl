#shader vertex
#version 410 core
layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vertexColor;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f);

    //gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vertexColor = projection * view * model * vec4(aPos, 1.0f);
}

#shader fragment
#version 410 core

in vec4 vertexColor;

out vec4 result;

void main()
{
    result = vec4(vertexColor.rgb, 1.0);
}
