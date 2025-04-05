#ifndef EXAMPLE_08_09_SKETCH_H
#define EXAMPLE_08_09_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_08_09_LSystem.h"
#include "Example_08_09_Turtle.h"

namespace nature_of_code_chapter_08_example_09
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.9: An L-system", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        LSystem     *_lsystem;
        Turtle      *_turtle;
    };
}

#endif
