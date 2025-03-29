#include "Example_04_05_Sketch.h"

namespace nature_of_code_chapter_04_example_05
{
    bool Sketch::Setup(void)
    {
        _emitter = new Emitter(Width() / 2, 20);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        _emitter->AddParticle();
        _emitter->Run(this);
        return true;
    }
}

// END
