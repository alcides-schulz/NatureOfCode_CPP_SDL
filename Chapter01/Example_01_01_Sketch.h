#ifndef EXAMPLE_01_01_SKETCH_H
#define EXAMPLE_01_01_SKETCH_H

#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_01_example_01
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 1.1: Bouncing ball with no vectors", -1, -1, 640, 240, 0) {}
        bool Setup() override;
        bool Draw() override;
    private:
        float   x_;
        float   y_;
        float   x_speed_;
        float   y_speed_;
    };
}

#endif
