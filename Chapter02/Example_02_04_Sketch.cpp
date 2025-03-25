#include "Example_02_04_Sketch.h"

namespace nature_of_code_chapter_02_example_04
{
    bool Sketch::Setup()
    {
        mover_ = new Mover(PVector(Width() / 2, 30), 5);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        PVector gravity(0.0f, 0.1f);
        mover_->ApplyForce(gravity);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            PVector wind(0.5f, 0.0f);
            mover_->ApplyForce(wind);
        }
    
        if (mover_->ContactEdge(this)) {
            float c = 0.1f;
            auto friction = mover_->GetVelocity().Clone();
            friction.Mult(-1);
            friction.SetMag(c);
            mover_->ApplyForce(friction);
        }
    
        mover_->BounceEdges(this);
        mover_->Update();
        mover_->Show(this);
    
        return true;
    }
    
}

// END
