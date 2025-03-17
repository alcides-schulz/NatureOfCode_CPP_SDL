#include "Particle_4_1.h"

void Particle_4_1::Update(void)
{
}

void Particle_4_1::Show(SDL_Framework *framework)
{
    framework->DrawCircle((int)location_.x, (int)location_.y, 48, kColorGray, true);
}

void Particle_4_1::CheckEdges(SDL_Framework *framework)
{
    if (location_.x > framework->Width())
        location_.x = 0;
    else if (location_.x < 0)
        location_.x = (float)framework->Width();
    if (location_.y > framework->Height())
        location_.y = 0;
    else if (location_.y < 0)
        location_.y = (float)framework->Height();
}

// END
