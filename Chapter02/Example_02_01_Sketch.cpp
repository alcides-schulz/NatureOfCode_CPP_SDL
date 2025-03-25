#include "Example_02_01_Sketch.h"

namespace nature_of_code_chapter_02_example_01
{
    bool Sketch::Setup()
    {
        mover_ = new Mover(PVector(Width() / 2, 30), 1);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        PVector gravity(0.0f, 0.1f);
        mover_->ApplyForce(gravity);
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            PVector wind(0.1f, 0.0f);
            mover_->ApplyForce(wind);
        }
    
        mover_->Update();
        mover_->CheckEdges(this);
        mover_->Show(this);
    
        return true;
    }
    
}

// END
