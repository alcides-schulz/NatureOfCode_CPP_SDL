#ifndef EXAMPLE_4_5_CONFETTI_H
#define EXAMPLE_4_5_CONFETTI_H

#include "../Common/SDL_Framework.h"

#include "Example_04_05_Particle.h"

namespace nature_of_code_chapter_04_example_05
{
    class Confetti : public Particle
    {
    public:
        Confetti(int x, int y) : Particle(x, y) {};
        void Show(SDL_Framework *framework) override;
    };
}

#endif
