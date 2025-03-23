#include "PerlinNoise2D.h"

double PerlinNoise2D::Noise(double x, double y)
{
    int X = (int)floor(x) & 255;
    int Y = (int)floor(y) & 255;
    x -= floor(x);
    y -= floor(y);
    double u = Fade(x);
    double v = Fade(y);
    int A = permutation_[X] + Y;
    int B = permutation_[X + 1] + Y;
    return Lerp(Lerp(Gradient(permutation_[permutation_[A]], x, y), Gradient(permutation_[permutation_[B]], x - 1, y), u),
                Lerp(Gradient(permutation_[permutation_[A + 1]], x, y - 1), Gradient(permutation_[permutation_[B + 1]], x - 1, y - 1), u), v);
}

double PerlinNoise2D::Lerp(double a, double b, double t)
{ 
    return a + t * (b - a); 
};

double PerlinNoise2D::Fade(double t)
{
    return t * t * t * (t * (t * 6 - 15) + 10); 
}

double PerlinNoise2D::Gradient(int hash, double x, double y)
{
    int h = hash & 3;
    double u = h < 2 ? x : y;
    double v = h < 2 ? y : x;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

// END
