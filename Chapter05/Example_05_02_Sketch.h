#ifndef EXAMPLE_05_02_SKETCH_H
#define EXAMPLE_05_02_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_05_02_Vehicle.h"

namespace nature_of_code_chapter_05_example_02
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 5.2: Arriving at a Target", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Vehicle     *vehicle_;
    };
}

#endif
