#include "Example_2_3.h"

bool Example_2_3::UserInit()
{
    PVector positionA(WindowWidth() / 4.0f, WindowHeight() / 2.0f);
    PVector positionB(WindowWidth() / 4.0f * 3, WindowHeight() / 2.0f);
    moverA_ = new Chapter02MoverV1(positionA, 5);
    moverB_ = new Chapter02MoverV1(positionB, 1);
    return true;
}

bool Example_2_3::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());
    PVector gravityA(0, 0.1f);
    gravityA.Mult((float)moverA_->GetMass());
    moverA_->ApplyForce(gravityA);
    PVector gravityB(0, 0.1f);
    gravityB.Mult((float)moverB_->GetMass());
    moverB_->ApplyForce(gravityB);
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
