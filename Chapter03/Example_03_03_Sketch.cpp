#include "Example_03_03_Sketch.h"

namespace nature_of_code_chapter_03_example_03
{
    bool Sketch::Setup(void)
    {
        _mover = new Mover(Vector(Width() / 2, Height() / 2));
    
        auto x = Vector(100, 50).Heading();
        cout << x << endl;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        _mover->Update(this);
        _mover->CheckEdges(this);
        _mover->Show(this);
    
        return true;
    }
    
}

// END
