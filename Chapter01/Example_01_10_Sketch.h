#ifndef EXAMPLE_01_10_SKETCH_H
#define EXAMPLE_01_10_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "Example_01_10_Mover.h"

namespace nature_of_code_chapter_01_example_10
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 1.10: Accelerating Toward the Mouse", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *mover_;
    };
}

#endif
