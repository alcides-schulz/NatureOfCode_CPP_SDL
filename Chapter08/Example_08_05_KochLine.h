#ifndef EXAMPLE_08_05_KOCHLINE_H
#define EXAMPLE_08_05_KOCHLINE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_08_example_05
{
    class KochLine
    {
    public:
        KochLine(P5SDL *p5sdl, Vector a, Vector b);
        void Show(void);
        array<Vector, 5> KochPoints(void);
    private:
        P5SDL   *_p5sdl;
        Vector  _start;
        Vector  _end;
    };
}

#endif
