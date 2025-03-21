#ifndef EXAMPLE_02_07_SKETCH_H
#define EXAMPLE_02_07_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_02_07_Mover.h"
#include "Example_02_07_Attractor.h"

namespace nature_of_code_chapter_02_example_07
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 2.7: Attraction with many movers", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Attractor       *attractor_;
        Mover           *mover_[10];
        bool            isDragging = false;
    };
}

#endif
