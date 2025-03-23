#ifndef PERLIN_NOISE_2D_H
#define PERLIN_NOISE_2D_H

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <numeric>

using namespace std;

class PerlinNoise2D
{
public:
    PerlinNoise2D(int seed = 0)
    {
        permutation_.resize(512);
        std::iota(permutation_.begin(), permutation_.begin() + 256, 0);
        std::mt19937 g(seed);
        std::shuffle(permutation_.begin(), permutation_.begin() + 256, g);
        std::copy(permutation_.begin(), permutation_.begin() + 256, permutation_.begin() + 256);
    }
    double Noise(double x, double y);
private:
    vector<int> permutation_;

    double Lerp(double a, double b, double t);
    double Fade(double t);
    double Gradient(int hash, double x, double y);
};

#endif
