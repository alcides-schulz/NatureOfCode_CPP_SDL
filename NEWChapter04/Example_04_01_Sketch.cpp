#include "Example_04_01_Sketch.h"

namespace nature_of_code_chapter_04_example_01
{
    bool Sketch::Setup(void)
    {
        particle_ = new Particle(Width() / 2, 10);
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        ClearScreen();
    
        particle_->Update();
        particle_->Show(this);
    
        auto gravity = PVector(0.0f, 0.1f);
        particle_->ApplyForce(gravity);
    
        if (particle_->IsDead()) {
            particle_ = new Particle(Width() / 2, 10);
            cout << "particle is dead !" << endl;
        }
    
        return true;
    }
    
}

// END
