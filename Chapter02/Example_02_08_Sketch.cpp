#include "Example_02_08_Sketch.h"

namespace nature_of_code_chapter_02_example_08
{
    bool Sketch::Setup()
    {
        _bodyA = new Body(Vector(320, 40), 8);
        _bodyB = new Body(Vector(320, 200), 8);
    
        _bodyA->SetVelocity(Vector(1, 0));
        _bodyB->SetVelocity(Vector(-1, 0));
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        _bodyA->Attract(_bodyB);
        _bodyB->Attract(_bodyA);
    
        _bodyA->Update();
        _bodyA->Show(this);
    
        _bodyB->Update();
        _bodyB->Show(this);
    
        return true;
    }
    
}

// END
