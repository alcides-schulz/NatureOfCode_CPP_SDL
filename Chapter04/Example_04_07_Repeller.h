#ifndef EXAMPLE_04_07_REPELLER_H
#define EXAMPLE_04_07_REPELLER_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"
#include "Example_04_07_Particle.h"

namespace nature_of_code_chapter_04_example_07
{
    class Repeller
    {
    public:
        Repeller(int x, int y)
        {
            position_ = PVector(x, y);
            power_ = 150;
        };
        PVector Repel(Particle *particle);
        void Show(SDL_Framework *framework);
    protected:
        PVector position_;
        float   power_;
    };
}


#endif

