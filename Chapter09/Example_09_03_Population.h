#ifndef EXAMPLE_09_03_POPULATION_H
#define EXAMPLE_09_03_POPULATION_H

#include "../Common/P5SDL.h"
#include "Example_09_03_Rocket.h"
#include "Example_09_03_Obstacle.h"

namespace nature_of_code_chapter_09_example_03
{
    class Population
    {
    public:
        Population(P5SDL *p5sdl, float mutation, int length);
        ~Population(void);
        void Live(vector<Obstacle *> obstacles);
        void CalculateFitness(void);
        void Selection(void);
        void Reproduction(void);
        DNA *WeightedSelection(void);
        int GetGenerations(void) { return _generations; };
        bool TargetReached(void);
    private:
        P5SDL *_p5sdl;
        float _mutation_rate;
        vector<Rocket *> _population;
        int _generations;
    };
}

#endif
