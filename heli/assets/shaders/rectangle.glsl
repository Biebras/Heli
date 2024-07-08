#shader vertex
#version 410 core
layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 UV;

uniform mat4 MVP;
uniform mat4 Model;

out vec2 uv;

void main()
{
    gl_Position = MVP * vec4(Pos, 1.0f);
    uv = UV;
}

#shader fragment
#version 410 core

#define EDGE_FADE 0.005

in vec2 uv;

uniform vec4 BaseColor;
uniform vec4 OutlineColor;
uniform float Thickness;
uniform vec4 CornerRadius;

out vec4 result;

// from https://iquilezles.org/articles/distfunctions
float roundedBoxSDF(vec2 uv, vec4 Radius) 
{
    uv = uv * 2.0 - 1.0;
    vec2 Size = vec2(1.0);
    vec2 CenterPosition = uv;

    Radius.xy = (CenterPosition.x > 0.0) ? Radius.yz : Radius.xw;
    Radius.x  = (CenterPosition.y > 0.0) ? Radius.x  : Radius.y;
    
    vec2 q = abs(CenterPosition)-Size+Radius.x;
    return min(max(q.x,q.y),0.0) + length(max(q,0.0)) - Radius.x;
}

void main()
{
    float distance = roundedBoxSDF(uv, CornerRadius);
    float smoothDistance = 1 - smoothstep(0.0f, EDGE_FADE, distance);

    float smoothBorder = 1.0f - smoothstep(Thickness - EDGE_FADE, Thickness, abs(distance));

    vec4 color = mix(BaseColor, OutlineColor, smoothBorder);
    color.a *= smoothDistance;

    result = color;
}
