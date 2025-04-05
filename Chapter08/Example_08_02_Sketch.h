#ifndef EXAMPLE_08_02_SKETCH_H
#define EXAMPLE_08_02_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_08_example_02
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.2: Recursive Cicles Twice", -1, -1, 640, 240, 0) {};
        bool Draw(void) override;
        void DrawCircles(int x, int y, int r);
    private:
    };
}

#endif
