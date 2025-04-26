#ifndef EXAMPLE_09_04_SKETCH_H
#define EXAMPLE_09_04_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Button.h"
#include "Example_09_04_Population.h"

namespace nature_of_code_chapter_09_example_04
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 9.4: Interactive Selection", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
        void NextGeneration(void);
    private:
        Population  *_population;
        Button      *_evolve_button;
    };
}

#endif
