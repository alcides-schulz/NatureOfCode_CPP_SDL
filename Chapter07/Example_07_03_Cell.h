#ifndef EXAMPLE_07_03_CELL_H
#define EXAMPLE_07_03_CELL_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_07_example_03
{
    class Cell : public P5SDL
    {
    public:
        Cell(P5SDL *p5sdl, int state, int x, int y, int w);
        void Show(void);
        int GetState(void) { return _state; };
        void SetState(int state) { _state = state; };
        int GetPrevious(void) { return _previous; };
        void SetPrevious(int state) { _previous = _state; };
    private:
        P5SDL *_p5sdl;
        int _state;
        int _previous;
        int _x;
        int _y;
        int _w;
    };
}

#endif
