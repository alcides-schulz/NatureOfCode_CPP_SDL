#include "Example_04_05_Sketch.h"

namespace nature_of_code_chapter_04_example_05
{
    bool Sketch::Setup(void)
    {
        emitter_ = new Emitter(Width() / 2, 20);
        return true;
    }

    bool Sketch::Draw(void)
    {
        ClearScreen();
        emitter_->AddParticle();
        emitter_->Run(this);
        return true;
    }
}

// END
