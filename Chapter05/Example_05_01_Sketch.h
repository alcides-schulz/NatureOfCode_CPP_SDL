#ifndef EXAMPLE_05_01_SKETCH_H
#define EXAMPLE_05_01_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_01_Vehicle.h"

namespace nature_of_code_chapter_05_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.1: Seeking a Target", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Vehicle *_vehicle;
    };
}

#endif
