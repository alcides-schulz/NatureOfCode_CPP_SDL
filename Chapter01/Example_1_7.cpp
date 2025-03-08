#include "Example_1_7.h"

bool Example_1_7::UserInit()
{
    auto location = PVector((float)(rand() % WindowWidth()), (float)(rand() % WindowHeight()));
    auto velocity = PVector((float)(rand() % 8 - 4), (float)(rand() % 8 - 4));
    mover_ = new Mover_1_7(location, velocity);
    return true;
}

bool Example_1_7::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

//END
