#include "Example_02_03_Sketch.h"

namespace nature_of_code_chapter_02_example_03
{
    bool Sketch::Setup()
    {
        _moverA = new Mover(Vector(200, 30), 10);
        _moverB = new Mover(Vector(440, 30), 2);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        Vector gravityA(0.0f, 0.1f);
        gravityA.Mult((float)_moverA->GetMass());
        _moverA->ApplyForce(gravityA);
    
        Vector gravityB(0.0f, 0.1f);
        gravityB.Mult((float)_moverB->GetMass());
        _moverB->ApplyForce(gravityB);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            Vector wind(0.1f, 0.0f);
            _moverA->ApplyForce(wind);
            _moverB->ApplyForce(wind);
        }
    
        _moverA->Update();
        _moverA->Show(this);
        _moverA->CheckEdges(this);
    
        _moverB->Update();
        _moverB->Show(this);
        _moverB->CheckEdges(this);
    
        return true;
    }
    
}

// END
