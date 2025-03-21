#include "Example_3_7.h"

bool Example_3_7::Setup(void)
{
    for (int i = 0; i < 10; i++) {
        oscillators_.push_back(new Oscillator_3_7(this));
    }

    return true;
}

bool Example_3_7::Draw()
{
    ClearScreen();

    for (int i = 0; i < oscillators_.size(); i++) {
        oscillators_[i]->Update();
        oscillators_[i]->Show(this);
    }

    return true;
}

// END
