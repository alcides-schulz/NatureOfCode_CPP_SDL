#include "Example_2_8.h"

bool Example_2_8::UserInit()
{
    bodyA_ = new Body_2_8(PVector(320, 40), 8);
    bodyB_ = new Body_2_8(PVector(320, 200), 8);

    bodyA_->SetVelocity(PVector(1, 0));
    bodyB_->SetVelocity(PVector(-1, 0));

    return true;
}

bool Example_2_8::UserRender(int elapsed_time)
{
    ClearScreen();

    bodyA_->Attract(bodyB_);
    bodyB_->Attract(bodyA_);

    bodyA_->Update();
    bodyA_->Display(this);

    bodyB_->Update();
    bodyB_->Display(this);

    return true;
}

// END