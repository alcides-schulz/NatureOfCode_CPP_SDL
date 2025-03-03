#include "Example_1_8.h"

bool Example_1_8::UserInit()
{
    PVector location((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
    PVector velocity(0, 0);
    mover_ = new Chapter01MoverV1(location, velocity);
    mover_->SetAcceleration(PVector(-0.001f, 0.01f));
    return true;
}

bool Example_1_8::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());
    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);
    return true;
}

// END
