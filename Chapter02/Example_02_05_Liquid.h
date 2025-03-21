#ifndef EXAMPLE_02_05_LIQUID_H
#define EXAMPLE_02_05_LIQUID_H

#include "../Common/SDL_Framework.h"
#include "Example_02_05_Mover.h"

namespace nature_of_code_chapter_02_example_05
{
    class Liquid
    {
    public:
        Liquid(int x, int y, int width, int height, float drag_coef) : x_(x), y_(y), width_(width), height_(height), drag_coef_(drag_coef) { };
        bool Contains(Mover    * mover);
        PVector CalculateDrag(Mover     *mover);
        void Show(SDL_Framework *framework);
    private:
        int     x_;
        int     y_;
        int     width_;
        int     height_;
        float   drag_coef_;
    };
}

#endif
