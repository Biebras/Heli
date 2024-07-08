#shader vertex
#version 410 core
layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 UV;

uniform mat4 MVP;
uniform mat4 Model;

out vec4 fragPos;

void main()
{
    gl_Position = MVP * vec4(Pos, 1.0f);
    fragPos = Model * vec4(Pos, 1.0f); 
}

#shader fragment
#version 410 core

float SmoothGrid(vec2 p, vec2 ddx, vec2 ddy);

const float GridRatio = 60.0;

in vec4 fragPos;

out vec4 result;

void main()
{
    vec2 world_uv = fragPos.xy - vec2(0.5 - (0.5 / GridRatio));
    vec2 ddx_uvw = dFdx(world_uv); 
    vec2 ddy_uvw = dFdy(world_uv);
    float grid = SmoothGrid(world_uv, ddx_uvw, ddy_uvw);
    grid = min(1, grid);
    result = vec4(grid, grid, grid, (1 - grid) * 0.5f);
}

float SmoothGrid(vec2 p, vec2 ddx, vec2 ddy)
{
	// filter kernel
    vec2 w = max(abs(ddx), abs(ddy)) + 0.01;

	// analytic (box) filtering
    vec2 a = p + 0.5 * w;                        
    vec2 b = p - 0.5 * w;           
    vec2 i = (floor(a) + min(fract(a) * GridRatio, 1.0) - floor(b) - min(fract(b) * GridRatio, 1.0)) / (GridRatio * w);
    // grid pattern
    return (1.0 - i.x)*(1.0 - i.y);
}
