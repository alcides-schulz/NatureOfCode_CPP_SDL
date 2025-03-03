#include "Example_2_4.h"

bool Example_2_4::UserInit()
{
    PVector position(WindowWidth() / 2.0f, WindowHeight() / 2.0f);
    mover_ = new Chapter02MoverV2(position, 5);
    return true;
}

bool Example_2_4::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());

    PVector gravity(0, 0.1f);
    gravity.Mult((float)mover_->GetMass());
    mover_->ApplyForce(gravity);

    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0);
        mover_->ApplyForce(wind);
    }

    if (mover_->ContactEdge(this)) {
        float c = 0.1f;
        PVector friction(mover_->GetVelocity().x, mover_->GetVelocity().y);
        friction.Mult(-1);
        friction.SetMag(c); // setMag()
        mover_->ApplyForce(friction);
    }

    mover_->BounceEdges(this);
    mover_->Update();
    mover_->Display(this);

    return true;
}

// END
