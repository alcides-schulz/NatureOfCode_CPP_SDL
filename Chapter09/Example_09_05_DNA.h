#ifndef EXAMPLE_09_05_DNA_H
#define EXAMPLE_09_05_DNA_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_09_example_05
{
    class DNA
    {
    public:
        DNA(void);
        DNA *Copy(void);
        void Mutate(float mutation_rate);
        vector<float> GetGenes(void) { return _genes; };
    private:
        vector<float> _genes;
    };
}

#endif
