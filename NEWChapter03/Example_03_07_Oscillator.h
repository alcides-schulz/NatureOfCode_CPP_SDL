#ifndef EXAMPLE_03_07_OSCILLATOR_H
#define EXAMPLE_03_07_OSCILLATOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_03_example_07
{
    class Oscillator
    {
    public:
        Oscillator(SDL_Framework *framework)
        {
            angle_ = PVector(0, 0);
            angle_velocity_ = PVector(Utils::Random(-0.05f, 0.05f), Utils::Random(-0.05f, 0.05f));
            amplitude_ = PVector(Utils::Random(20.0f, (float)framework->Width()), Utils::Random(20.0f, (float)framework->Height()));
        };
        void Update(void);
        void Show(SDL_Framework *framework);
    private:
        PVector angle_;
        PVector angle_velocity_;
        PVector amplitude_;
    };
}

#endif
