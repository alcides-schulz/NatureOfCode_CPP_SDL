#include "Example_2_8.h"

bool Example_2_8::UserInit()
{
    bodyA_ = new Body(PVector(WindowWidth() / 4.0f * 1, WindowHeight() / 4.0f * 1), 2);
    bodyA_->SetVelocity(PVector(1, 0));
    bodyB_ = new Body(PVector(WindowWidth() / 4.0f * 3, WindowHeight() / 4.0f * 3), 2);
    bodyB_->SetVelocity(PVector(-1, 0));
    return true;
}

bool Example_2_8::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());

    bodyA_->Attract(bodyB_);
    bodyB_->Attract(bodyA_);

    bodyA_->Update();
    bodyA_->Display(this);

    bodyB_->Update();
    bodyB_->Display(this);

    return true;
}

// END