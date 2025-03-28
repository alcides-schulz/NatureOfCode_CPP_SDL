#include "Example_02_06_Sketch.h"

namespace nature_of_code_chapter_02_example_06
{
    bool Sketch::Setup()
    {
        mover_ = new Mover(Vector(300, 50), 2);
        attractor_ = new Attractor(Vector(Width() / 2.0f, Height() / 2.0f), 20);
    
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        if (!isDragging && IsMouseButtonHeld(kMouseLeftButton)) {
            auto mouse_position = Vector((float)MousePosition().x, (float)MousePosition().y);
            auto distance = Vector::Distance(mouse_position, attractor_->GetPosition());
            if (distance <= attractor_->GetRadius()) {
                isDragging = true;
            }
        }
        if (isDragging && IsMouseButtonHeld(kMouseLeftButton)) {
            attractor_->SetPosition(Vector((float)MousePosition().x, (float)MousePosition().y));
        }
        if (!IsMouseButtonHeld(kMouseLeftButton)) {
            isDragging = false;
        }
    
        attractor_->Show(this);
    
        Vector force = attractor_->Attract(mover_);
        mover_->ApplyForce(force);
        mover_->Update();
        mover_->Show(this);
    
        return true;
    }
    
}

// END
