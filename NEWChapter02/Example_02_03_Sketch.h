#ifndef EXAMPLE_02_03_SKETCH_H
#define EXAMPLE_02_03_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_02_03_Mover.h"

namespace nature_of_code_chapter_02_example_03
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 2.3: Gravity scaled by Mass", -1, -1, 640, 240, 0) {};
        bool Setup() override;
        bool Draw() override;
    private:
        Mover       *moverA_;
        Mover       *moverB_;
    };
}

#endif
