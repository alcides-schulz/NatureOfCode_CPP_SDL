#ifndef EXAMPLE_08_09_TURTLE_H
#define EXAMPLE_08_09_TURTLE_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_08_example_09
{
    class Turtle
    {
    public:
        Turtle(P5SDL *p5sdl, int length, double angle);
        void Render(string sentence);
    private:
        P5SDL   *_p5sdl;
        int     _lenght;
        double  _angle;
    };
}

#endif
