#include "Example_01_10_Sketch.h"

namespace nature_of_code_chapter_01_example_10
{
    bool Sketch::Setup()
    {
        Vector location(Width() / 2, Height() / 2);
        Vector velocity(0, 0);
        _mover = new Mover(location, velocity);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        auto direction = Vector(MousePosition().x, MousePosition().y);
        direction.Sub(_mover->GetPosition());
        direction.Normalize();
        direction.Mult(0.2f);
        _mover->SetAcceleration(direction);
    
        _mover->Update();
        _mover->Show(this);
    
        return true;
    }
    
}

// END
