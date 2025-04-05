#ifndef EXAMPLE_08_07_SKETCH_H
#define EXAMPLE_08_07_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_08_example_07
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.7: A Stochastic Tree", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Branch(int lenght);
    };
}

#endif
