#include "Example_3_2.h"
#include "../Common/Utils.h"

bool Example_3_2::Setup()
{
    for (int i = 0; i < std::size(mover_); i++) {
        auto x = Utils::Random((float)Width());
        auto y = Utils::Random((float)Height());
        auto m = (int)Utils::Random(1.0f, 4.0f);
        mover_[i] = new Mover_3_2(PVector(x, y), m);
        auto vx = Utils::Random(-1, 1);
        auto vy = Utils::Random(-1, 1);
        mover_[i]->SetVelocity(PVector(vx, vy));
    }
    attractor_ = new Attractor_3_2(PVector(Width() / 2.0f, Height() / 2.0f), 20);
    return true;
}

bool Example_3_2::Draw()
{
    ClearScreen();

    if (!isDragging && IsMouseButtonPressed(kMouseLeftButton)) {
        auto mouse_position = PVector((float)MousePosition().x, (float)MousePosition().y);
        auto distance = PVector::Distance(mouse_position, attractor_->GetPosition());
        if (distance <= attractor_->GetRadius()) {
            isDragging = true;
        }
    }
    if (isDragging && IsMouseButtonPressed(kMouseLeftButton)) {
        attractor_->SetPosition(PVector((float)MousePosition().x, (float)MousePosition().y));
    }
    if (!IsMouseButtonPressed(kMouseLeftButton)) {
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