#include "Example_01_09_Sketch.h"

namespace nature_of_code_chapter_01_example_09
{
    bool Sketch::Setup()
    {
        PVector location((float)(Width() / 2), (float)(Height() / 2));
        PVector velocity(0, 0);
        mover_ = new Mover(location, velocity);
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
