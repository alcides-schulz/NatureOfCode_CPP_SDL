#include "Example_01_07_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_01_example_07
{
    
    bool Sketch::Setup()
    {
        auto location = PVector(Utils::Random((float)Width()), Utils::Random((float)Height()));
        auto velocity = PVector(Utils::Random(-2, 2), Utils::Random(-2, 2));
        mover_ = new Mover(location, velocity);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        ClearScreen();
    
        mover_->Update();
        mover_->CheckEdges(this);
        mover_->Show(this);
    
        return true;
    }
    
}

// END
