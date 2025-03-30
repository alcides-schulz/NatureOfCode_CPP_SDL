#include "Vector.h"

void Vector::Add(Vector other)
{
    this->x += other.x;
    this->y += other.y;
}

void Vector::Sub(Vector other)
{
    this->x -= other.x;
    this->y -= other.y;
}

void Vector::Mult(float value)
{
    this->x *= value;
    this->y *= value;
}

void Vector::Div(float value)
{
    this->x /= value;
    this->y /= value;
}

float Vector::Mag()
{
    return sqrtf(this->x * this->x + this->y * this->y);
}

void Vector::Normalize()
{
    float magnitude = Mag();
    if (magnitude != 0) {
        Div(magnitude);
    }
}

void Vector::SetMag(float magnitude)
{
    Normalize();
    Mult(magnitude);
}

void Vector::Limit(float max)
{
    if (Mag() > max * max) {
        Normalize();
        Mult(max);
    }
}

float Vector::Heading(void)
{
    return std::atan2(y, x);
}

Vector Vector::Clone(void)
{
    return Vector(x, y);
}

float Vector::Dot(Vector other)
{
    return x * other.x + y * other.y;
}

Vector Vector::Random2D()
{
    float angle = (static_cast<float>(rand()) / RAND_MAX) * 2.0f * static_cast<float>(M_PI);
    return Vector(std::cos(angle), std::sin(angle));
}

float Vector::Distance(Vector vector1, Vector vector2)
{
    auto dx = std::abs(vector1.x - vector2.x);
    auto dy = std::abs(vector1.y - vector2.y);
    return sqrt(dx * dx + dy * dy);
}

Vector Vector::Add(Vector vector1, Vector vector2)
{
    return Vector(vector1.x + vector2.x, vector1.y + vector2.y);
}

Vector Vector::Sub(Vector vector1, Vector vector2)
{
    return Vector(vector1.x - vector2.x, vector1.y - vector2.y);
}

Vector Vector::FromAngle(double angle)
{
    return Vector((float)cos(angle), (float)sin(angle));
}

// End