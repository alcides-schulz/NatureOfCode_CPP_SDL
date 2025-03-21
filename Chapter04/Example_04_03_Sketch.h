#ifndef EXAMPLE_04_03_SKETCH_H
#define EXAMPLE_04_03_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_04_03_Emitter.h"

namespace nature_of_code_chapter_04_example_03
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 4.3: A Single Particle Emitter", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Emitter         *emitter_;
    };
}

#endif
