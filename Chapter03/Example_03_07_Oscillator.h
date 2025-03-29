#ifndef EXAMPLE_03_07_OSCILLATOR_H
#define EXAMPLE_03_07_OSCILLATOR_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_03_example_07
{
    class Oscillator
    {
    public:
        Oscillator(P5SDL *p5sdl)
        {
            _angle = Vector(0, 0);
            _angle_velocity = Vector(Utils::Random(-0.05f, 0.05f), Utils::Random(-0.05f, 0.05f));
            _amplitude = Vector(Utils::Random(20.0f, (float)p5sdl->Width()), Utils::Random(20.0f, (float)p5sdl->Height()));
        };
        void Update(void);
        void Show(P5SDL *p5sdl);
    private:
        Vector _angle;
        Vector _angle_velocity;
        Vector _amplitude;
    };
}

#endif
