#include "Example_2_3.h"

bool Example_2_3::UserInit()
{
    moverA_ = new Mover_2_3(PVector(200, 30), 10);
    moverB_ = new Mover_2_3(PVector(440, 30), 2);
    return true;
}

bool Example_2_3::UserRender(int elapsed_time)
{
    ClearScreen();

    PVector gravityA(0.0f, 0.1f);
    gravityA.Mult((float)moverA_->GetMass());
    moverA_->ApplyForce(gravityA);
    
    PVector gravityB(0.0f, 0.1f);
    gravityB.Mult((float)moverB_->GetMass());
    moverB_->ApplyForce(gravityB);
    
    if (IsMouseButtonPressed(kMouseLeftButton)) {
        PVector wind(0.1f, 0.0f);
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
