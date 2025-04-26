#ifndef EXAMPLE_09_04_DNA_H
#define EXAMPLE_09_04_DNA_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_09_example_04
{
    class DNA
    {
    public:
        DNA();
        DNA *Crossover(DNA *partner);
        void Mutate(float mutation_rate);
        vector<float> GetGenes(void) { return _genes; };
    private:
        vector<float>   _genes;
    };
}

#endif
