#include "PVector.h"

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

float PVector::Heading(void)
{
    return std::atan2(y, x);
}

PVector PVector::Clone(void)
{
    return PVector(x, y);
}

PVector PVector::Random2D()
{
    float angle = (static_cast<float>(rand()) / RAND_MAX) * 2.0f * static_cast<float>(PI_VALUE);
    return PVector(std::cos(angle), std::sin(angle));
}

float PVector::Distance(PVector vector1, PVector vector2)
{
    auto dx = std::abs(vector1.x - vector2.x);
    auto dy = std::abs(vector1.y - vector2.y);
    return sqrt(dx * dx + dy * dy);
}

// End