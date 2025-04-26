#ifndef EXAMPLE_09_04_POPULATION_H
#define EXAMPLE_09_04_POPULATION_H

#include "../Common/P5SDL.h"
#include "Example_09_04_Flower.h"

namespace nature_of_code_chapter_09_example_04
{
    class Population
    {
    public:
        Population(P5SDL *p5sdl, float mutation_rate, int size);
        ~Population(void);
        void Show(void);
        void Rollover(int mouse_x, int mouse_y);
        Flower *WeightedSelection(void);
        void Selection(void);
        void Reproduction(void);
        int GetGeneration(void) { return _generations; };
    private:
        P5SDL   *_p5sdl;
        float   _mutation_rate;
        int     _generations;
        vector<Flower *> _flowers;
    };
}

#endif
