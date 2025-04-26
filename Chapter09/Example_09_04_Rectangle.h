#ifndef EXAMPLE_09_04_RECTANGLE_H
#define EXAMPLE_09_04_RECTANGLE_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_09_example_04
{
    class Rectangle
    {
    public:
        Rectangle(P5SDL *p5sdl, int x, int y, int w, int h);
        bool Contains(int px, int py);
        void Show(void);
    private:
        P5SDL *_p5sdl;
        int _x;
        int _y;
        int _w;
        int _h;
    };
}

#endif
