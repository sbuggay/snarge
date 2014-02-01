#include "devmath.h"

float dist(float a, float b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}

float dist(Vector2f a, Vector2f b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

float get_angle(float a, float b)
{
    return atan2(b, a);
}

float get_angle(Vector2f vec)
{
    return atan2(vec.y, vec.x);
}

float to_radians(float a)
{
    return a * PI / 180;
}

float to_degrees(float b)
{
    return b * 180 / PI;
}

float normalize(float a)
{
    return 0;
}

sf::Vector2f norm(sf::Vector2f in)
{
    float length = dist(in.x, in.y);
    return sf::Vector2f(in.x/length,in.y/length);
}
