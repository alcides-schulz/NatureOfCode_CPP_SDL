#ifndef EXAMPLE_03_01_SKETCH_H
#define EXAMPLE_03_01_SKETCH_H

#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_03_example_01
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.1: Angular Motion with rotation", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        float   angle_;
        float   angleVelocity_;
        float   angleAcceleration_;
    };
}

#endif
