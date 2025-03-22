#ifndef EXAMPLE_05_03_SKETCH_H
#define EXAMPLE_05_03_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_05_03_Vehicle.h"

namespace nature_of_code_chapter_05_example_03
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 5.3: 'Stay Within Walls' Steering Behavior", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Vehicle     *vehicle_;
        int         offset_;
        bool        debug_;
    };
}

#endif
