#ifndef EXAMPLE_03_11_SKETCH_H
#define EXAMPLE_03_11_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_03_11_Pendulum.h"

namespace nature_of_code_chapter_03_example_11
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.11: Swinging Pendulum", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        Pendulum        *pendulum_;
    };
}

#endif
