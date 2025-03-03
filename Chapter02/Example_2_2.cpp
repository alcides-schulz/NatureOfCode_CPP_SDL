#include "Example_2_2.h"

bool Example_2_2::UserInit()
{
    PVector positionA(WindowWidth() / 4.0f, WindowHeight() / 2.0f);
    PVector positionB(WindowWidth() / 4.0f * 3, WindowHeight() / 2.0f);
    moverA_ = new Chapter02MoverV1(positionA, 10);
    moverB_ = new Chapter02MoverV1(positionB, 1);
    return true;
}

bool Example_2_2::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());
    PVector gravity(0, 0.1f);
    moverA_->ApplyForce(gravity);
    moverB_->ApplyForce(gravity);
    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0);
        moverA_->ApplyForce(wind);
        moverB_->ApplyForce(wind);
    }
    moverA_->Update();
    moverA_->Display(this);
    moverA_->CheckEdges(this);
    moverB_->Update();
    moverB_->Display(this);
    moverB_->CheckEdges(this);
    return true;
}

// END
