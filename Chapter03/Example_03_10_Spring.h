#ifndef EXAMPLE_03_10_SPRING_H
#define EXAMPLE_03_10_SPRING_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_03_10_Bob.h"

namespace nature_of_code_chapter_03_example_10
{
    class Spring
    {
    public:
        Spring(Vector anchor, float length) : _anchor(anchor), _rest_length(length)
        {
            _k = 0.2f;
        };
        void Connect(Bob      *bob);
        void ConstrainLength(Bob      *bob, float min_length, float max_length);
        void Show(P5SDL *p5sdl);
        void ShowLine(P5SDL *p5sdl, Bob      *bob);
    private:
        Vector  _anchor;
        float   _rest_length;
        float   _k;
    };
}

#endif
