#include "Example_01_10_Sketch.h"

namespace nature_of_code_chapter_01_example_10
{
    bool Sketch::Setup()
    {
        PVector location(Width() / 2, Height() / 2);
        PVector velocity(0, 0);
        mover_ = new Mover(location, velocity);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        auto direction = PVector(MousePosition().x, MousePosition().y);
        direction.Sub(mover_->GetPosition());
        direction.Normalize();
        direction.Mult(0.2f);
        mover_->SetAcceleration(direction);
    
        mover_->Update();
        mover_->Show(this);
    
        return true;
    }
    
}

// END
