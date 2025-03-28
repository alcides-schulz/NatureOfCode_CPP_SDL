#include "Example_03_02_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_03_example_02
{
    
    bool Sketch::Setup()
    {
        for (int i = 0; i < std::size(mover_); i++) {
            auto x = Utils::Random((float)Width());
            auto y = Utils::Random((float)Height());
            auto m = (int)Utils::Random(1.0f, 4.0f);
            mover_[i] = new Mover(Vector(x, y), m);
            auto vx = Utils::Random(-1, 1);
            auto vy = Utils::Random(-1, 1);
            mover_[i]->SetVelocity(Vector(vx, vy));
        }
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
    
        for (int i = 0; i < std::size(mover_); i++) {
            Vector force = attractor_->Attract(mover_[i]);
            mover_[i]->ApplyForce(force);
            mover_[i]->Update();
            mover_[i]->Show(this);
        }
    
        return true;
    }
    
}

// END
