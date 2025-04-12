#ifndef EXAMPLE_09_03_DNA_H
#define EXAMPLE_09_03_DNA_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_09_example_03
{
    const int kLifeSpan = 250;

    class DNA
    {
    public:
        DNA();
        DNA *Crossover(DNA *partner);
        void Mutate(float m);
        Vector GetGene(int counter) { return _genes[counter]; };
        int Length(void) { return (int)_genes.size(); };
    private:
        array<Vector, kLifeSpan> _genes;
        float _max_force;
    };
}

#endif
