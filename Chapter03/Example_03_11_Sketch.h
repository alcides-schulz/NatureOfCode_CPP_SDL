#ifndef EXAMPLE_03_11_SKETCH_H
#define EXAMPLE_03_11_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_03_11_Pendulum.h"

namespace nature_of_code_chapter_03_example_11
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 3.11: Swinging Pendulum", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Pendulum    *_pendulum;
    };
}

#endif
