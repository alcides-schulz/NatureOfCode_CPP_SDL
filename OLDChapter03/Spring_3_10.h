#ifndef SPRING_3_10_H
#define SPRING_3_10_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Bob_3_10.h"

class Spring_3_10
{
public:
    Spring_3_10(PVector anchor, float length) : anchor_(anchor), rest_length_(length)
    {
        k_ = 0.2f;
    };
    void Connect(Bob_3_10 *bob);
    void ConstrainLength(Bob_3_10 *bob, float min_length, float max_length);
    void Show(SDL_Framework *framework);
    void ShowLine(SDL_Framework *framework, Bob_3_10 *bob);
private:
    PVector anchor_;
    float   rest_length_;
    float   k_;
};

#endif

