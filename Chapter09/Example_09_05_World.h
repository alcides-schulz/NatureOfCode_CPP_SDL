#ifndef EXAMPLE_09_05_WORLD_H
#define EXAMPLE_09_05_WORLD_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

#include "Example_09_05_Bloop.h"
#include "Example_09_05_DNA.h"
#include "Example_09_05_Food.h"

namespace nature_of_code_chapter_09_example_05
{
    class World
    {
    public:
        World(P5SDL *p5sdl, int population_size);
        void Run(void);
        void Born(void);
    private:
        P5SDL   *_p5sdl;
        vector<Bloop *> _bloops;
        Food    *_food;
    };
}

#endif
