#ifndef EXAMPLE_04_07_REPELLER_H
#define EXAMPLE_04_07_REPELLER_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "Example_04_07_Particle.h"

namespace nature_of_code_chapter_04_example_07
{
    class Repeller
    {
    public:
        Repeller(int x, int y)
        {
            position_ = Vector(x, y);
            power_ = 150;
        };
        Vector Repel(Particle *particle);
        void Show(P5SDL *p5sdl);
    protected:
        Vector position_;
        float   power_;
    };
}


#endif

