#ifndef EXAMPLE_03_09_SKETCH_H
#define EXAMPLE_03_09_SKETCH_H

#include "../Common/SDL_Framework.h"

namespace nature_of_code_chapter_03_example_09
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.9: The Wave", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        float   start_angle_;
        float   angle_velocity_;
    };
}

#endif
