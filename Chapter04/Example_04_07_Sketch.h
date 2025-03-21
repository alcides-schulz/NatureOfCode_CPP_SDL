#ifndef EXAMPLE_04_07_SKETCH_H
#define EXAMPLE_04_07_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_04_07_Emitter.h"
#include "Example_04_07_Repeller.h"

namespace nature_of_code_chapter_04_example_07
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 4.7: A Particle System with Repellers", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Emitter     *emitter_;
        Repeller    *repeller_;
    };
}

#endif
