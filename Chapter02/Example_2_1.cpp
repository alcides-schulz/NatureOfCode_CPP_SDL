#include "Example_2_1.h"

bool Example_2_1::UserInit()
{
    PVector position(WindowWidth() / 2.0f, WindowHeight() / 2.0f);
    mover_ = new Chapter02MoverV1(position, 1);
    return true;
}

bool Example_2_1::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());
    PVector gravity(0, 0.1f);
    mover_->ApplyForce(gravity);
    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0);
        mover_->ApplyForce(wind);
    }
    mover_->Update();
    mover_->Display(this);
    mover_->CheckEdges(this);
    return true;
}

// END
