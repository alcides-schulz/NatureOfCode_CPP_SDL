#ifndef EXAMPLE_01_06_SKETCH_H
#define EXAMPLE_01_06_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_01_example_06
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 1.6: Normalizing a vector", -1, -1, 640, 240, 0) {}
        bool Draw() override;
    };
}

#endif
