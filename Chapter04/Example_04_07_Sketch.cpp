#include "Example_04_07_Sketch.h"

namespace nature_of_code_chapter_04_example_07
{
    bool Sketch::Setup(void)
    {
        emitter_ = new Emitter(Width() / 2, 50);
        repeller_ = new Repeller(Width() / 2, 230);
        return true;
    }

    bool Sketch::Draw(void)
    {
        ClearScreen();
        emitter_->AddParticle();
        auto gravity = PVector(0.0f, 0.1f);
        emitter_->ApplyForce(gravity);
        emitter_->ApplyRepeller(repeller_);
        emitter_->Run(this);
        repeller_->Show(this);
        return true;
    }
}

// END
