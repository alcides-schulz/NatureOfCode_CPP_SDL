#ifndef EXAMPLE_4_5_SKETCH_H
#define EXAMPLE_4_5_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

#include "Example_04_05_Emitter.h"

namespace nature_of_code_chapter_04_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.5: A Particle System with Inheritance and Polymorphism", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Emitter *_emitter;
    };
}

#endif
