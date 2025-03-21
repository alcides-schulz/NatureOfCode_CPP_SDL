#ifndef OSCILLATOR_3_7_H
#define OSCILLATOR_3_7_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"

class Oscillator_3_7
{
public:
    Oscillator_3_7(SDL_Framework *framework)
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

#endif

