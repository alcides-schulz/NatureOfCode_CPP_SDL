#include "Example_04_07_Sketch.h"

namespace nature_of_code_chapter_04_example_07
{
    bool Sketch::Setup(void)
    {
        _emitter = new Emitter(Width() / 2, 50);
        _repeller = new Repeller(Width() / 2, 230);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        _emitter->AddParticle();
        auto gravity = Vector(0.0f, 0.1f);
        _emitter->ApplyForce(gravity);
        _emitter->ApplyRepeller(_repeller);
        _emitter->Run(this);
        _repeller->Show(this);
        return true;
    }
}

// END
