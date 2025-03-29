#include "Example_01_09_Sketch.h"

namespace nature_of_code_chapter_01_example_09
{
    bool Sketch::Setup()
    {
        Vector location((float)(Width() / 2), (float)(Height() / 2));
        Vector velocity(0, 0);
        _mover = new Mover(location, velocity);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        _mover->Update();
        _mover->CheckEdges(this);
        _mover->Show(this);
    
        return true;
    }
    
}

// END
