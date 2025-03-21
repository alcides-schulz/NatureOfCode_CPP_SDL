#include "Example_4_4.h"

bool Example_4_4::Setup(void)
{
    cout << "Click to add particle system." << endl;
    return true;
}

bool Example_4_4::Draw(void)
{
    ClearScreen();
    if (IsMouseButtonClicked(kMouseLeftButton)) {
        emitters_.push_back(new Emitter_4_4(MousePosition().x, MousePosition().y));
    }
    if (IsMouseButtonClicked(kMouseRightButton) && emitters_.size() > 0) {
        emitters_.erase(emitters_.begin());
    }
    for each (auto emitter in emitters_)
    {
        emitter->AddParticle();
        emitter->Run(this);
    }
    return true;
}

// END
