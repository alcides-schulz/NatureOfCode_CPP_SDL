#ifndef UTILS_H
#define UTILS_H

#define _USE_MATH_DEFINES
#include <cmath>

class Utils
{
public:
    double static Map(double value, double start1, double stop1, double start2, double stop2)
    {
        return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
    }

    float static Radians(float degrees)
    {
        return static_cast<float>(degrees * M_PI / 180);
    }

    float static Random(float max)
    {
        return (float)rand() / RAND_MAX * max;
    }

    float static Random(float min, float max)
    {
        return (float)rand() / RAND_MAX * (max - min) + min;
    }
};

#endif

// END
