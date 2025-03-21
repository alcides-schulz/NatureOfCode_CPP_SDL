#ifndef EXAMPLE_4_5_SKETCH_H
#define EXAMPLE_4_5_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"

#include "Example_04_05_Emitter.h"

namespace nature_of_code_chapter_04_example_05
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 04.05: A Particle System with Inheritance and Polymorphism", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Emitter     *emitter_;
    };
}

#endif
