#include "Example_01_08_Sketch.h"

namespace nature_of_code_chapter_01_example_08
{
    bool Sketch::Setup()
    {
        auto location = Vector(Width() / 2, Height() / 2);
        auto velocity = Vector(0, 0);
        mover_ = new Mover(location, velocity);
        mover_->SetAcceleration(Vector(-0.001f, 0.01f));
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        mover_->Update();
        mover_->CheckEdges(this);
        mover_->Show(this);
    
        return true;
    }
    
}

// END
