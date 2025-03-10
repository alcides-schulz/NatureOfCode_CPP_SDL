#include "Example_2_5.h"

bool Example_2_5::UserInit()
{
    liquid_ = new Liquid_2_5(0, WindowHeight() / 2, WindowWidth(), WindowHeight() / 2, 0.1f);
    for (int i = 0; i < std::size(mover_); i++) {
        mover_[i] = nullptr;
    }
    Reset();
    return true;
}

bool Example_2_5::UserRender(int elapsed_time)
{
    ClearScreen();

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
        mover_[i]->Update();
        mover_[i]->CheckEdges(this);
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
        mover_[i] = new Mover_2_5(PVector((float)(30 + WindowWidth() / 10 * i), 0), (int)((rand() % 3) + 1.0f));
    }
}

// END
