#ifndef EXAMPLE_02_06_SKETCH_H
#define EXAMPLE_02_06_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_02_06_Mover.h"
#include "Example_02_06_Attractor.h"

namespace nature_of_code_chapter_02_example_06
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 2.6: Attraction", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Attractor       *attractor_;
        Mover           *mover_;
        bool            isDragging = false;
    };
}

#endif
