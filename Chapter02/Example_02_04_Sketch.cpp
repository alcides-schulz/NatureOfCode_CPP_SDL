#include "Example_02_04_Sketch.h"

namespace nature_of_code_chapter_02_example_04
{
    bool Sketch::Setup()
    {
        _mover = new Mover(Vector(Width() / 2, 30), 5);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        Vector gravity(0.0f, 0.1f);
        _mover->ApplyForce(gravity);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            Vector wind(0.5f, 0.0f);
            _mover->ApplyForce(wind);
        }
    
        if (_mover->ContactEdge(this)) {
            float c = 0.1f;
            auto friction = _mover->GetVelocity().Copy();
            friction.Mult(-1);
            friction.SetMag(c);
            _mover->ApplyForce(friction);
        }
    
        _mover->BounceEdges(this);
        _mover->Update();
        _mover->Show(this);
    
        return true;
    }
    
}

// END
