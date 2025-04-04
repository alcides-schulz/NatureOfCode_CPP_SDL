#include "Example_04_01_Sketch.h"

namespace nature_of_code_chapter_04_example_01
{
    bool Sketch::Setup(void)
    {
        _particle = new Particle(Width() / 2, 10);
        return true;
    }
    
    bool Sketch::Draw(void)
    {
        Background(255);
    
        _particle->Update();
        _particle->Show(this);
    
        auto gravity = Vector(0.0f, 0.05f);
        _particle->ApplyForce(gravity);
    
        if (_particle->IsDead()) {
            _particle = new Particle(Width() / 2, 10);
            cout << "particle is dead !" << endl;
        }
    
        return true;
    }
    
}

// END
