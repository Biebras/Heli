#include <cmath>
#include <glm/glm.hpp>

float VectorDistance(glm::vec2 vec1, glm::vec2 vec2)
{
   float x = vec2.x - vec1.x;
   float y = vec2.y - vec1.y;
   return sqrt(x*x+y*y);
}

float clamp(float value, float min, float max) 
{
    return std::fmax(min, std::fmin(max, value));
}
