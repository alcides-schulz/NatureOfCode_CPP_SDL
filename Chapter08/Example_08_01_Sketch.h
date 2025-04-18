#ifndef EXAMPLE_08_01_SKETCH_H
#define EXAMPLE_08_01_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_08_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.1: Recursive Cicles Once", -1, -1, 640, 240, 0) {};
        bool Draw(void) override;
        void DrawCircles(int x, int y, int r);
    private:
    };
}

#endif
