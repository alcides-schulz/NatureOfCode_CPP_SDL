#ifndef EXAMPLE_03_03_SKETCH_H
#define EXAMPLE_03_03_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_03_03_Mover.h"

namespace nature_of_code_chapter_03_example_03
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.3: Pointing in the direction of motion", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        Mover           *mover_;
    };
}

#endif
