#include "Example_2_6.h"

bool Example_2_6::UserInit()
{
    mover_ = new Chapter02MoverV1(PVector(300, 0), 2);
    mover_->SetVelocity(PVector(1, 0));
    attractor_ = new Attractor(PVector(WindowWidth() / 2.0f, WindowHeight() / 2.0f), 10);
    return true;
}

bool Example_2_6::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
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

    PVector force = attractor_->Attract(mover_);
    mover_->ApplyForce(force);
    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

// END