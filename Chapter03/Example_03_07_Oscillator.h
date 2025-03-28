#ifndef EXAMPLE_03_07_OSCILLATOR_H
#define EXAMPLE_03_07_OSCILLATOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_03_example_07
{
    class Oscillator
    {
    public:
        Oscillator(SDL_Framework *framework)
        {
            angle_ = Vector(0, 0);
            angle_velocity_ = Vector(Utils::Random(-0.05f, 0.05f), Utils::Random(-0.05f, 0.05f));
            amplitude_ = Vector(Utils::Random(20.0f, (float)framework->Width()), Utils::Random(20.0f, (float)framework->Height()));
        };
        void Update(void);
        void Show(SDL_Framework *framework);
    private:
        Vector angle_;
        Vector angle_velocity_;
        Vector amplitude_;
    };
}

#endif
