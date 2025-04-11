#ifndef EXAMPLE_09_01_SKETCH_H
#define EXAMPLE_09_01_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_09_01_DNA.h"

namespace nature_of_code_chapter_09_example_01
{
    const double kMutationRate = 0.01;
    const int    kPopulationSize = 150;
    const string kTarget = "to be or not to be";

    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 9.1: Genetic Algorithm for Evolving Shakespeare", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        vector<DNA *>   _population;


    };
}

#endif
