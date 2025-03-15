#include "Example_3_2.h"

bool Example_3_2::Setup()
{
    for (int i = 0; i < std::size(mover_); i++) {
        auto x = (float)(std::rand() % Width());
        auto y = (float)(std::rand() % Height());
        auto m = std::rand() % 2 + 1;
        mover_[i] = new Mover_3_2(PVector(x, y), m);
        auto vx = rand() / RAND_MAX * 2.0f - 1.0f;
        auto vy = rand() / RAND_MAX * 2.0f - 1.0f;
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