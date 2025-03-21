#ifndef EXAMPLE_01_05_SKETCH_H
#define EXAMPLE_01_05_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_01_example_05
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 1.5: Vector Magnitude", -1, -1, 640, 240, 0) {}
        bool Draw() override;
    };
}

#endif
