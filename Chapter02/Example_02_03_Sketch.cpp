#include "Example_02_03_Sketch.h"

namespace nature_of_code_chapter_02_example_03
{
    bool Sketch::Setup()
    {
        moverA_ = new Mover(PVector(200, 30), 10);
        moverB_ = new Mover(PVector(440, 30), 2);
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        PVector gravityA(0.0f, 0.1f);
        gravityA.Mult((float)moverA_->GetMass());
        moverA_->ApplyForce(gravityA);
    
        PVector gravityB(0.0f, 0.1f);
        gravityB.Mult((float)moverB_->GetMass());
        moverB_->ApplyForce(gravityB);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            PVector wind(0.1f, 0.0f);
            moverA_->ApplyForce(wind);
            moverB_->ApplyForce(wind);
        }
    
        moverA_->Update();
        moverA_->Show(this);
        moverA_->CheckEdges(this);
    
        moverB_->Update();
        moverB_->Show(this);
        moverB_->CheckEdges(this);
    
        return true;
    }
    
}

// END
