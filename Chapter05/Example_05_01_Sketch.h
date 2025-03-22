#ifndef EXAMPLE_05_01_SKETCH_H
#define EXAMPLE_05_01_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_05_01_Vehicle.h"

namespace nature_of_code_chapter_05_example_01
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 05.01: Seeking a Target", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Vehicle     *vehicle_;
    };
}

#endif
