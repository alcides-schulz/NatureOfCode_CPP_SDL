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
            angle_ = Vector(0, 0);
            angle_velocity_ = Vector(Utils::Random(-0.05f, 0.05f), Utils::Random(-0.05f, 0.05f));
            amplitude_ = Vector(Utils::Random(20.0f, (float)p5sdl->Width()), Utils::Random(20.0f, (float)p5sdl->Height()));
        };
        void Update(void);
        void Show(P5SDL *p5sdl);
    private:
        Vector angle_;
        Vector angle_velocity_;
        Vector amplitude_;
    };
}

#endif
