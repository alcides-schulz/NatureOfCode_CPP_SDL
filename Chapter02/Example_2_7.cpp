#include "Example_2_7.h"
#include "../Common/Utils.h"

bool Example_2_7::Setup()
{
    for (int i = 0; i < std::size(mover_); i++) {
        auto x = Utils::Random((float)Width());
        auto y = Utils::Random((float)Height());
        auto m = (int)Utils::Random(1, 4);
        mover_[i] = new Mover_2_7(PVector(x, y), m);
    }
    attractor_ = new Attractor_2_7(PVector(Width() / 2.0f, Height() / 2.0f), 20);

    return true;
}

bool Example_2_7::Draw()
{
    ClearScreen();

    if (!isDragging && IsMouseButtonHeld(kMouseLeftButton)) {
        auto mouse_position = PVector((float)MousePosition().x, (float)MousePosition().y);
        auto distance = PVector::Distance(mouse_position, attractor_->GetPosition());
        if (distance <= attractor_->GetRadius()) {
            isDragging = true;
        }
    }
    if (isDragging && IsMouseButtonHeld(kMouseLeftButton)) {
        attractor_->SetPosition(PVector((float)MousePosition().x, (float)MousePosition().y));
    }
    if (!IsMouseButtonHeld(kMouseLeftButton)) {
        isDragging = false;
    }

    attractor_->Show(this);

    for (int i = 0; i < std::size(mover_); i++) {
        PVector force = attractor_->Attract(mover_[i]);
        mover_[i]->ApplyForce(force);
        mover_[i]->Update();
        mover_[i]->Show(this);
    }

    return true;
}

// END