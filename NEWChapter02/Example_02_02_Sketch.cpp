#include "Example_02_02_Sketch.h"

namespace nature_of_code_chapter_02_example_02
{
    bool Sketch::Setup()
    {
        moverA_ = new Mover(PVector(200, 30), 10);
        moverB_ = new Mover(PVector(440,30), 2);
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        PVector gravity(0.0f, 0.1f);
        moverA_->ApplyForce(gravity);
        moverB_->ApplyForce(gravity);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            PVector wind(0.1f, 0.0f);
            moverA_->ApplyForce(wind);
            moverB_->ApplyForce(wind);
        }
    
        moverA_->Update();
        moverA_->CheckEdges(this);
        moverA_->Show(this);
    
        moverB_->Update();
        moverB_->CheckEdges(this);
        moverB_->Show(this);
    
        return true;
    }
    
}

// END
