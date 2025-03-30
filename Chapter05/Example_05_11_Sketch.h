#ifndef EXAMPLE_05_11_SKETCH_H
#define EXAMPLE_05_11_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_11_Flock.h"

namespace nature_of_code_chapter_05_example_11
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.11: Flocking", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Flock   *_flock;
    };
}

#endif
