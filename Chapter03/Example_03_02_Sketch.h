#ifndef EXAMPLE_03_02_SKETCH_H
#define EXAMPLE_03_02_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_03_02_Mover.h"
#include "Example_03_02_Attractor.h"

namespace nature_of_code_chapter_03_example_02
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.2: Forces with (Arbitrary) Angular Motion", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Attractor       *attractor_;
        Mover           *mover_[10];
        bool            isDragging = false;
    };
}

#endif
