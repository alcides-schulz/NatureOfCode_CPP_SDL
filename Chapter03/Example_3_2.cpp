#include "Example_3_2.h"

bool Example_3_2::UserInit()
{
    for (int i = 0; i < std::size(mover_); i++) {
        auto x = (float)(std::rand() % WindowWidth());
        auto y = (float)(std::rand() % WindowHeight());
        auto m = std::rand() % 3 + 1;
        mover_[i] = new Mover_3_2(PVector(x, y), m);
        auto vx = rand() / RAND_MAX * 2.0f - 1.0f;
        auto vy = rand() / RAND_MAX * 2.0f - 1.0f;
        mover_[i]->SetVelocity(PVector(vx, vy));
    }
    attractor_ = new Attractor_3_2(PVector(WindowWidth() / 2.0f, WindowHeight() / 2.0f), 10);
    return true;
}

bool Example_3_2::UserRender(int elapsed_time)
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

    attractor_->Display(this);

    for (int i = 0; i < std::size(mover_); i++) {
        PVector force = attractor_->Attract(mover_[i]);
        mover_[i]->ApplyForce(force);
        mover_[i]->Update();
        mover_[i]->Display(this);
    }

    return true;
}

// END