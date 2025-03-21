#include "Example_4_1.h"

bool Example_4_1::Setup(void)
{
    particle_ = new Particle_4_1(Width() / 2, 10);
    return true;
}

bool Example_4_1::Draw(void)
{
    ClearScreen();

    particle_->Update();
    particle_->Show(this);

    auto gravity = PVector(0.0f, 0.1f);
    particle_->ApplyForce(gravity);

    if (particle_->IsDead()) {
        particle_ = new Particle_4_1(Width() / 2, 10);
        cout << "particle is dead !" << endl;
    }

    return true;
}

// END
