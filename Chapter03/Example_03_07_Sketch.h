#ifndef EXAMPLE_03_07_SKETCH_H
#define EXAMPLE_03_07_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_03_07_Oscillator.h"

namespace nature_of_code_chapter_03_example_07
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 3.7: Oscillator Objects", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw() override;
    private:
        std::vector<Oscillator     *> oscillators_;
    };
}

#endif
