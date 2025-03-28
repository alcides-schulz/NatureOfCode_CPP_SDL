#include "Example_02_08_Sketch.h"

namespace nature_of_code_chapter_02_example_08
{
    bool Sketch::Setup()
    {
        bodyA_ = new Body(Vector(320, 40), 8);
        bodyB_ = new Body(Vector(320, 200), 8);
    
        bodyA_->SetVelocity(Vector(1, 0));
        bodyB_->SetVelocity(Vector(-1, 0));
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        bodyA_->Attract(bodyB_);
        bodyB_->Attract(bodyA_);
    
        bodyA_->Update();
        bodyA_->Show(this);
    
        bodyB_->Update();
        bodyB_->Show(this);
    
        return true;
    }
    
}

// END
