#ifndef EXAMPLE_01_03_SKETCH_H
#define EXAMPLE_01_03_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_01_example_03
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 1.3: PVector subtraction", -1, -1, 640, 240, 0) {}
        bool Draw() override;
    };
}

#endif
