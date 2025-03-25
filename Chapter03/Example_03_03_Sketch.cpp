#include "Example_03_03_Sketch.h"

namespace nature_of_code_chapter_03_example_03
{
    bool Sketch::Setup(void)
    {
        mover_ = new Mover(PVector(Width() / 2, Height() / 2));
    
        auto x = PVector(100, 50).Heading();
        cout << x << endl;
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        mover_->Update(this);
        mover_->CheckEdges(this);
        mover_->Show(this);
    
        return true;
    }
    
}

// END
