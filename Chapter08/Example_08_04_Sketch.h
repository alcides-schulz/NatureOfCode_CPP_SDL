#ifndef EXAMPLE_08_04_SKETCH_H
#define EXAMPLE_08_04_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_08_example_04
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.4: The Cantor Set", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cantor(int x, int y, int length);
    private:
    };
}

#endif
