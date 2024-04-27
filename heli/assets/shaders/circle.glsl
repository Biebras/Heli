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

#define EDGE_FADE 0.005
#define RADIUS 0.25

in vec2 uv;

out vec4 result;

void main()
{
    vec2 cUV = uv - 0.5f; 

    float r = cUV.x * cUV.x + cUV.y * cUV.y;

    float thickness = 0.005;

    float big_circle = smoothstep(RADIUS, RADIUS - EDGE_FADE, r);

    vec4 small_circle = vec4(smoothstep(RADIUS - thickness, RADIUS - EDGE_FADE - thickness, r));
    vec4 border = vec4(big_circle - small_circle) * vec4(0, 0, 0, 1); 
    vec4 circle = small_circle * vec4(0.6, 0.3, 0.2, 1) + border; 

    result = vec4(circle);
}
