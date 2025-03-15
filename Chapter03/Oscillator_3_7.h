#ifndef OSCILLATOR_3_7_H
#define OSCILLATOR_3_7_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Oscillator_3_7
{
public:
    Oscillator_3_7(SDL_Framework *framework)
    {
        angle_ = PVector(0, 0);

        auto angle_velocity_x = static_cast<float>((double)std::rand() / RAND_MAX * 0.1 - 0.05);
        auto angle_velocity_y = static_cast<float>((double)std::rand() / RAND_MAX * 0.1 - 0.05);
        angle_velocity_ = PVector(angle_velocity_x, angle_velocity_y);

        auto amplitude_x = static_cast<float>(std::rand() % (framework->WindowWidth() / 2) + 20);
        auto amplitude_y = static_cast<float>(std::rand() % (framework->WindowHeight() / 2) + 20);
        amplitude_ = PVector(amplitude_x, amplitude_y);
    };
    void Update(void);
    void Display(SDL_Framework *framework);
private:
    PVector angle_;
    PVector angle_velocity_;
    PVector amplitude_;
};

#endif

