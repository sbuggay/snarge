#ifndef DEVMATH_H
#define DEVMATH_H

#include <cmath>

#include <SFML/Graphics.hpp>

using namespace sf;

#define PI 3.141592f

float dist(float a, float b);

float dist(Vector2f a, Vector2f b);

float get_angle(float a, float b);

float get_angle(Vector2f vec);

float to_radians(float a);

float to_degrees(float b);

float normalize(float a);

sf::Vector2f norm(sf::Vector2f in);


#endif // DEVMATH_H
