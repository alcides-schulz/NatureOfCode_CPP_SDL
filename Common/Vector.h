#ifndef VECTOR_H
#define VECTOR_H

#define _USE_MATH_DEFINES
#include <cmath>

class Vector
{
public:
    float x;
    float y;
    Vector() : x(0), y(0) {};
    Vector(float x, float y) : x(x), y(y) { };
    Vector(int x, int y) : x((float)x), y((float)y) { };
    void Add(Vector other);
    void Sub(Vector other);
    void Mult(float value);
    void Div(float value);
    float Mag();
    void Normalize();
    void SetMag(float max);
    void Limit(float max);
    float Heading(void);
    Vector Clone(void);
    float Dot(Vector other);
    static Vector Random2D();
    static float Distance(Vector vector1, Vector vector2);
    static Vector Add(Vector vector1, Vector vector2);
    static Vector Sub(Vector vector1, Vector vector2);
    static Vector FromAngle(double angle);
};

#endif
