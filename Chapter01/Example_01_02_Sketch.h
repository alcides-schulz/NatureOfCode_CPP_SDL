#ifndef EXAMPLE_01_02_SKETCH_H
#define EXAMPLE_01_02_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_01_example_02
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 1.2: Bouncing ball with PVectors", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        PVector position_;
        PVector velocity_;
    };
}

#endif
