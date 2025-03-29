#include "Example_05_04_Vehicle.h"

namespace nature_of_code_chapter_05_example_04
{

    void Vehicle::Run(P5SDL *p5sdl)
    {
        Update();
        Borders(p5sdl);
        Show(p5sdl);
    }

    void Vehicle::Follow(FlowField *flowfield)
    {
        auto desired = flowfield->Lookup(position_);
        desired.Mult(max_speed_);
        auto steer = Vector::Sub(desired, velocity_);
        steer.Limit(max_force_);
        ApplyForce(steer);
    }
    
    void Vehicle::ApplyForce(Vector force)
    {
        acceleration_.Add(force);
    }

    void Vehicle::Update(void)
    {
        velocity_.Add(acceleration_);
        velocity_.Limit(max_speed_);
        position_.Add(velocity_);
        acceleration_.Mult(0);
    }
    
    void Vehicle::Borders(P5SDL *p5sdl)
    {
        if (position_.x < -r_) position_.x = (float)(p5sdl->Width() + r_);
        if (position_.y < -r_) position_.y = (float)(p5sdl->Height() + r_);
        if (position_.x > p5sdl->Width() + r_) position_.x = (float)-r_;
        if (position_.y > p5sdl->Height() + r_) position_.y = (float)-r_;
    }

    void Vehicle::Show(P5SDL *p5sdl)
    {
        p5sdl->Translate(position_.x, position_.y);
        auto angle = velocity_.Heading();
        p5sdl->Rotate(angle);
        SDL_Point vertices[] = { 
            {r_ * 2, 0}, 
            {-r_ * 2, -r_}, 
            {-r_ * 2, r_},
            {r_ * 2, 0},
        };
        p5sdl->Stroke(kColorBlack);
        p5sdl->Lines(vertices, sizeof(vertices) / sizeof(SDL_Point));
        p5sdl->ResetMatrix();
    }
}
 
// END
