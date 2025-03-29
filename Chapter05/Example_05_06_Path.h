#ifndef EXAMPLE_05_06_PATH_H
#define EXAMPLE_05_06_PATH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_06
{
    class Path
    {
    public:
        Path(P5SDL *p5sdl);
        void Show(P5SDL *p5sdl);
        Vector GetStart(void) { return _start; };
        Vector GetEnd(void) { return _end; };
        int GetRadius(void) { return _radius; };
    private:
        int     _radius;
        Vector  _start;
        Vector  _end;
    };
}

#endif

