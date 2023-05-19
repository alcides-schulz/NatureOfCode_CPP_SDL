#pragma once

#include <cmath>

const double PI_VALUE = 3.141592653589793238463;

class PVector
{
public:
    float x;
    float y;
    PVector() : x(0), y(0) {};
    PVector(float x, float y);
    void Add(PVector other);
    void Sub(PVector other);
    void Mult(float value);
    void Div(float value);
    float Mag();
    void Normalize();
    void Limit(float max);
    static PVector Random2D();
};
