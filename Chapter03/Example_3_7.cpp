#include "Example_3_7.h"

bool Example_3_7::UserInit(void)
{
    for (int i = 0; i < 10; i++) {
        oscillators_.push_back(new Oscillator_3_7(this));
    }

    return true;
}

bool Example_3_7::UserRender(int elapsed_time)
{
    ClearScreen();

    for (int i = 0; i < oscillators_.size(); i++) {
        oscillators_[i]->Update();
        oscillators_[i]->Display(this);
    }

    return true;
}

// END
