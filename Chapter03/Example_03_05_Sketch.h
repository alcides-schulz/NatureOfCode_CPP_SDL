#ifndef EXAMPLE_03_05_SKETCH_H
#define EXAMPLE_03_05_SKETCH_H

#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_03_example_05
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.5: Simple Harmonic Motion", -1, -1, 640, 240, 0) {};
        bool Draw() override;
    };
}

#endif
