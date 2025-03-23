#pragma once

#include <cmath>

const double PI_VALUE = 3.141592653589793238463;

class PVector
{
public:
    float x;
    float y;
    PVector() : x(0), y(0) {};
    PVector(float x, float y) : x(x), y(y) { };
    PVector(int x, int y) : x((float)x), y((float)y) { };
    void Add(PVector other);
    void Sub(PVector other);
    void Mult(float value);
    void Div(float value);
    float Mag();
    void Normalize();
    void SetMag(float max);
    void Limit(float max);
    double Heading(void);
    PVector Clone(void);
    static PVector Random2D();
    static float Distance(PVector vector1, PVector vector2);
    static PVector Add(PVector vector1, PVector vector2);
    static PVector Sub(PVector vector1, PVector vector2);
    static PVector FromAngle(double angle);
};
