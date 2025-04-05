#include "Example_08_09_Turtle.h"

namespace nature_of_code_chapter_08_example_09
{
    Turtle::Turtle(P5SDL *p5sdl, int length, double angle)
    {
        _p5sdl = p5sdl;
        _lenght = length;
        _angle = angle;
    }

    void Turtle::Render(string sentence)
    {
        _p5sdl->Stroke(0);
        for (int i = 0; i < sentence.length(); i++) {
            auto c = sentence[i];
            if (c == 'F' || c == 'G') {
                _p5sdl->Line(0, 0, 0, -_lenght);
                _p5sdl->Translate(0, -_lenght);
            } 
            else if (c == '+') {
                _p5sdl->Rotate(_angle);
            }
            else if (c == '-') {
                _p5sdl->Rotate(-_angle);
            }
            else if (c == '[') {
                _p5sdl->Push();
            }
            else if (c == ']') {
                _p5sdl->Pop();
            }
        }
    }
}

// END
