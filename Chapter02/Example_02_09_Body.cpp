#include "Example_02_09_Body.h"

namespace nature_of_code_chapter_02_example_09
{
    void Body::ApplyForce(PVector force)
    {
        PVector temp = force.Clone();
        temp.Div((float)mass_);
        acceleration_.Add(temp);
    }
    
    void Body::Update(void)
    {
        velocity_.Add(acceleration_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }
    
    void Body::Show(SDL_Framework *framework)
    {
        framework->DrawCircle((int)position_.x, (int)position_.y, mass_ * 16, kColorGray, true);
    }
    
    void Body::Attract(Body *body)
    {
        auto force = PVector(position_.x, position_.y);
        force.Sub(body->GetPosition());
        auto distance = force.Mag();
        distance = (float)std::fmax(5, std::fmin(25, distance));
        auto strength = (kGravity * mass_ * body->GetMass()) / (distance * distance);
        force.SetMag(strength);
        body->ApplyForce(force);
    }
    
}

// END
