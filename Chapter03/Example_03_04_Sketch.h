#ifndef EXAMPLE_03_04_SKETCH_H
#define EXAMPLE_03_04_SKETCH_H

#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_03_example_04
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.4: Polar to cartesian", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        float   radius;
        float   theta;
    };
}

#endif
