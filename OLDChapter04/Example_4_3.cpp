#include "Example_4_3.h"

bool Example_4_3::Setup(void)
{
    emitter_ = new Emitter_4_3(Width() / 2, 50);
    return true;
}

bool Example_4_3::Draw(void)
{
    ClearScreen();
    emitter_->AddParticle();
    emitter_->Run(this);
    return true;
}

// END
