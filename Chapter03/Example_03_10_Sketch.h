#ifndef EXAMPLE_03_10_SKETCH_H
#define EXAMPLE_03_10_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_03_10_Bob.h"
#include "Example_03_10_Spring.h"

namespace nature_of_code_chapter_03_example_10
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.10: A Spring Connection", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        Bob         *bob_;
        Spring      *spring_;
    };
}

#endif
