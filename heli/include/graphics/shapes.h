#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>

void InitShapes();
void DrawCircle(glm::vec3 position, float radius, float thickness, glm::vec4 baseColor, glm::vec4 outlineColor);

#endif
