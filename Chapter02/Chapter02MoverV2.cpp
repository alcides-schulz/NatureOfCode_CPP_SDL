#include "Chapter02MoverV2.h"

void Chapter02MoverV2::ApplyForce(PVector force)
{
    PVector temp = PVector(force);
    temp.Div((float)mass_);
    acceleration_.Add(temp);
}

void Chapter02MoverV2::Update(void)
{
    velocity_.Add(acceleration_);
    position_.Add(velocity_);
    acceleration_.Mult(0);
}

void Chapter02MoverV2::Display(SDL_Framework *framework)
{
    framework->DrawCircle({ (int)position_.x, (int)position_.y }, radius_, { 255, 0, 0, 0 }, true);
}

void Chapter02MoverV2::CheckEdges(SDL_Framework *framework)
{
    if (position_.x > framework->WindowWidth() - radius_) {
        position_.x = (float)framework->WindowWidth() - radius_;
        velocity_.x *= -1;
    }
    if (position_.x < radius_) {
        position_.x = (float)radius_;
        velocity_.x *= -1;
    }
    if (position_.y > framework->WindowHeight() - radius_) {
        position_.y = (float)framework->WindowHeight() - radius_;
        velocity_.y *= -1;
    }
    if (position_.y < radius_) {
        position_.y = (float)radius_;
        velocity_.y *= -1;
    }
}

bool Chapter02MoverV2::ContactEdge(SDL_Framework *framework)
{
    return position_.y > framework->WindowWidth() - radius_ - 1;
}

void Chapter02MoverV2::BounceEdges(SDL_Framework *framework)
{
    float bounce = -0.9f;
    if (position_.x > framework->WindowWidth() - radius_) {
        position_.x = (float)(framework->WindowWidth() - radius_);
        velocity_.x *= bounce;
    }
    else if (position_.x < radius_) {
        position_.x = (float)radius_;
        velocity_.x *= bounce;
    }
    if (position_.y > framework->WindowHeight() - radius_) {
        position_.y = (float)(framework->WindowHeight() - radius_);
        velocity_.y *= bounce;
    }
}

// EOF