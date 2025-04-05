#include "Example_07_03_Cell.h"

namespace nature_of_code_chapter_07_example_03
{
    Cell::Cell(P5SDL *p5sdl, int state, int x, int y, int w)
    {
        _p5sdl = p5sdl;
        _state = state;
        _previous = _state;
        _x = x;
        _y = y;
        _w = w;
    }

    void Cell::Show()
    {
        Stroke(0);
        StrokeWeight(1);
        if (_previous == 0 && _state == 1)
            _p5sdl->Fill({ 0, 0, 255, 255 });
        else if (_state == 1)
            _p5sdl->Fill(0);
        else if (_previous == 1 && _state == 0)
            _p5sdl->Fill({ 255, 0, 0, 255 });
        else
            _p5sdl->Fill(255);
        _p5sdl->Square(_x, _y, _w);
    }
}

// END
