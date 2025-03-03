#include "PVector.h"

PVector::PVector(float x, float y)
{
    this->x = x;
    this->y = y;
}

void PVector::Add(PVector other)
{
    this->x += other.x;
    this->y += other.y;
}

void PVector::Sub(PVector other)
{
    this->x -= other.x;
    this->y -= other.y;
}

void PVector::Mult(float value)
{
    this->x *= value;
    this->y *= value;
}

void PVector::Div(float value)
{
    this->x /= value;
    this->y /= value;
}

float PVector::Mag()
{
    return sqrtf(this->x * this->x + this->y * this->y);
}

void PVector::Normalize()
{
    float magnitude = Mag();
    if (magnitude != 0) {
        Div(magnitude);
    }
}

void PVector::SetMag(float magnitude)
{
    Normalize();
    Mult(magnitude);
}

void PVector::Limit(float max)
{
    if (Mag() > max * max) {
        Normalize();
        Mult(max);
    }
}

PVector PVector::Random2D()
{
    float min = -1;
    float max = +1;
    float r = (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
    float angle = (float)(r * PI_VALUE * 2);
    return PVector(cos(angle), sin(angle));
}

float PVector::Distance(PVector vector1, PVector vector2)
{
    auto dx = std::abs(vector1.x - vector2.x);
    auto dy = std::abs(vector1.y - vector2.y);
    return sqrt(dx * dx + dy * dy);
}

// End