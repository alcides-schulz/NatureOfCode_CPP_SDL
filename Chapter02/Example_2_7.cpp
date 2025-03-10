#include "Example_2_7.h"

bool Example_2_7::UserInit()
{
    for (int i = 0; i < std::size(mover_); i++) {
        auto x = (float)(std::rand() % WindowWidth());
        auto y = (float)(std::rand() % WindowHeight());
        auto m = std::rand() % 3 + 1;
        mover_[i] = new Mover_2_7(PVector(x, y), m);
    }
    attractor_ = new Attractor_2_7(PVector(WindowWidth() / 2.0f, WindowHeight() / 2.0f), 20);
    return true;
}

bool Example_2_7::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.b, kColorWhite.g, 255);
    SDL_RenderClear(Renderer());

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