#ifndef EXAMPLE_09_01_DNA_H
#define EXAMPLE_09_01_DNA_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_09_example_01
{
    class DNA
    {
    public:
        DNA(int length);
        string GetPhase(void) { return _genes; };
        void CalculateFitness(string target);
        DNA *Crossover(DNA *partner);
        void Mutate(double mutation_rate);
        double GetFitness(void) { return _fitness; };
    private:
        char RandomCharacter(void);

        string _genes;
        double _fitness;
    };
}

#endif
