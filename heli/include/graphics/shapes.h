#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>

void InitShapes();
void DrawCircle(glm::vec3 position, float radius, float thickness, glm::vec4 baseColor, glm::vec4 outlineColor);
void DrawRectangle(glm::vec2 topLeftCorner, glm::vec2 botRightCorner, glm::vec4 baseColor);
void DrawGrid();

#endif
