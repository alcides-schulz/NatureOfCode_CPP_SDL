#include "Oscillator_3_7.h"

void Oscillator_3_7::Update()
{
    angle_.Add(angle_velocity_);
}

void Oscillator_3_7::Display(SDL_Framework *framework)
{
    auto x = static_cast<int>(std::sin(angle_.x) * amplitude_.x);
    auto y = static_cast<int>(std::sin(angle_.y) * amplitude_.y);

    framework->Translate(framework->WindowWidth() / 2, framework->WindowHeight() / 2);
    framework->DrawLine(0, 0, x, y, kColorBlack);
    framework->DrawCircle(x, y, 32, kColorGray, true);
    framework->ResetMatrix();
}

// EOF