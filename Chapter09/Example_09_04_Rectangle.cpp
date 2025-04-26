#include "Example_09_04_Rectangle.h"

namespace nature_of_code_chapter_09_example_04
{
    Rectangle::Rectangle(P5SDL *p5sdl, int x, int y, int w, int h)
    {
        _p5sdl = p5sdl;
        _x = x;
        _y = y;
        _w = w;
        _h = h;
    }

    bool Rectangle::Contains(int px, int py)
    {
        return px > _x && px < _x + _w && py > _y && py < _y + _h;
    }

    void Rectangle::Show(void)
    {
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(2);
        _p5sdl->Rect(_x, _y, _w, _h);
    }
}

// END
