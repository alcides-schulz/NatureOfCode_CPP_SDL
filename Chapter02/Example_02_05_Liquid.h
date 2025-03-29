#ifndef EXAMPLE_02_05_LIQUID_H
#define EXAMPLE_02_05_LIQUID_H

#include "../Common/P5SDL.h"
#include "Example_02_05_Mover.h"

namespace nature_of_code_chapter_02_example_05
{
    class Liquid
    {
    public:
        Liquid(int x, int y, int width, int height, float drag_coef) : _x(x), _y(y), _width(width), _height(height), _drag_coef(drag_coef) { };
        bool Contains(Mover * mover);
        Vector CalculateDrag(Mover *mover);
        void Show(P5SDL *p5sdl);
    private:
        int     _x;
        int     _y;
        int     _width;
        int     _height;
        float   _drag_coef;
    };
}

#endif
