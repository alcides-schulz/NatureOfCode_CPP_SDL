#ifndef EXAMPLE_09_02_SKETCH_H
#define EXAMPLE_09_02_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_09_example_02
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 9.2: Smart Rockets", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
    };
}

#endif
