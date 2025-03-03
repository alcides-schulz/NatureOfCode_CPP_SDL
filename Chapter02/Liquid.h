#ifndef LIQUID_H
#define LIQUID_H

#include "../Common/SDL_Framework.h"
#include "Chapter02MoverV3.h"

class Liquid
{
public:
    Liquid(int x, int y, int width, int height, float drag_coef) : x_(x), y_(y), width_(width), height_(height), drag_coef_(drag_coef) { };
    bool Contains(Chapter02MoverV3* mover);
    PVector CalculateDrag(Chapter02MoverV3 *mover);
    void Display(SDL_Framework *framework);
private:
    int     x_;
    int     y_;
    int     width_;
    int     height_;
    float   drag_coef_;
};

#endif
