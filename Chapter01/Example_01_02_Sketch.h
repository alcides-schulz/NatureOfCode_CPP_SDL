#ifndef EXAMPLE_01_02_SKETCH_H
#define EXAMPLE_01_02_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_01_example_02
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 1.2: Bouncing ball with PVectors", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        Vector _position;
        Vector _velocity;
    };
}

#endif
