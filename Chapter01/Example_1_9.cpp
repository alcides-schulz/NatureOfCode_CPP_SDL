#include "Example_1_9.h"

bool Example_1_9::UserInit()
{
    PVector location((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
    PVector velocity(0, 0);
    mover_ = new Mover_1_9(location, velocity);
    return true;
}

bool Example_1_9::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

// END
