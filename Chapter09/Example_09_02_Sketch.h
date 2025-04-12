#ifndef EXAMPLE_09_02_SKETCH_H
#define EXAMPLE_09_02_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_09_02_Population.h"

namespace nature_of_code_chapter_09_example_02
{
    extern Vector gTarget;
    
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 9.2: Smart Rockets", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Population *_population;
        int _life_span;
        int _life_counter;
    };
}

#endif
