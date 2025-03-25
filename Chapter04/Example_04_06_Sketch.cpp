#include "Example_04_06_Sketch.h"

namespace nature_of_code_chapter_04_example_06
{
    bool Sketch::Setup(void)
    {
        emitter_ = new Emitter(Width() / 2, 50);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        emitter_->AddParticle();
        emitter_->Run(this);
        return true;
    }
}

// END
