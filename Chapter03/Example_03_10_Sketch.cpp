#include "Example_03_10_Sketch.h"

namespace nature_of_code_chapter_03_example_10
{
    bool Sketch::Setup(void)
    {
        spring_ = new Spring(PVector(Width() / 2, 10), 100);
        bob_ = new Bob(PVector(Width() / 2, 100));
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        if (IsMouseButtonHeld(kMouseLeftButton))
            bob_->HandleClick(MousePosition().x, MousePosition().y);
        else
            bob_->StopDragging();
    
        auto gravity = PVector(0, 2);
        bob_->ApplyForce(gravity);
        bob_->Update(this);
        bob_->HandleDrag(MousePosition().x, MousePosition().y);
    
        spring_->Connect(bob_);
        spring_->ConstrainLength(bob_, 30, 200);
        spring_->ShowLine(this, bob_);
    
        bob_->Show(this);
        spring_->Show(this);
    
        return true;
    }
    
}

// END
