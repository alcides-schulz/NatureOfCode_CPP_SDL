#include "Example_2_5.h"

bool Example_2_5::UserInit()
{
    liquid_ = new Liquid(0, WindowHeight() / 2, WindowWidth(), WindowHeight() / 2, 0.1f);
    for (int i = 0; i < std::size(mover_); i++) {
        mover_[i] = nullptr;
    }
    Reset();
    return true;
}

bool Example_2_5::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());
    if (IsMouseButtonPressed(kMouseLeftButton)) {
        Reset();
    }
    liquid_->Display(this);
    for (int i = 0; i < std::size(mover_); i++) {
        if (liquid_->Contains(mover_[i])) {
            auto dragForce = liquid_->CalculateDrag(mover_[i]);
            mover_[i]->ApplyForce(dragForce);
        }
        PVector gravity(0, 0.1f);
        gravity.Mult((float)mover_[i]->GetMass());
        mover_[i]->ApplyForce(gravity);
        mover_[i]->CheckEdges(this);
        mover_[i]->Update();
        mover_[i]->Display(this);
    }
    return true;
}

void Example_2_5::Reset(void)
{
    for (int i = 0; i < std::size(mover_); i++) {
        if (mover_[i] != nullptr) {
            delete mover_[i];
        }
        PVector position((float)(WindowWidth() / std::size(mover_) * i + WindowWidth() / 10), 0);
        mover_[i] = new Chapter02MoverV3(position, std::rand() % 10 + 1);
    }
}

// END
