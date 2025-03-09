#ifndef LIQUID_2_5_H
#define LIQUID_2_5_H

#include "../Common/SDL_Framework.h"
#include "Mover_2_5.h"

class Liquid_2_5
{
public:
    Liquid_2_5(int x, int y, int width, int height, float drag_coef) : x_(x), y_(y), width_(width), height_(height), drag_coef_(drag_coef) { };
    bool Contains(Mover_2_5* mover);
    PVector CalculateDrag(Mover_2_5 *mover);
    void Display(SDL_Framework *framework);
private:
    int     x_;
    int     y_;
    int     width_;
    int     height_;
    float   drag_coef_;
};

#endif
