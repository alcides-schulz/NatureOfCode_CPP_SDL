#ifndef EXAMPLE_09_05_SKETCH_H
#define EXAMPLE_09_05_SKETCH_H

#include "../Common/P5SDL.h"

#include "Example_09_05_World.h"

namespace nature_of_code_chapter_09_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 9.5: An Evolving Ecosystem", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        World *_world;
    };
}

#endif
