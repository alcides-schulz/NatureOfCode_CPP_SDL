#ifndef EXAMPLE_05_05_PATH_H
#define EXAMPLE_05_05_PATH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_05
{
    class Path
    {
    public:
        Path(P5SDL *p5sdl)
        {
            _radius = 20;
            _start = Vector(0, p5sdl->Height() / 3);
            _end = Vector(p5sdl->Width(), (2 * p5sdl->Height()) / 3);
        }
        void Show(P5SDL *p5sdl);
    private:
        int     _radius;
        Vector  _start;
        Vector  _end;
    };
}

#endif

