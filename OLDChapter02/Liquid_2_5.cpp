#include "Liquid_2_5.h"

bool Liquid_2_5::Contains(Mover_2_5 *mover)
{
    PVector& loc = mover->GetPosition();
    return loc.x > x_ && loc.x < x_ + width_ && loc.y > y_ && loc.y + y_ + height_;
}

PVector Liquid_2_5::CalculateDrag(Mover_2_5 *mover)
{
    float speed = mover->GetVelocity().Mag();
    float drag_magnitude = drag_coef_ * speed * speed;
    PVector drag_force = PVector(mover->GetVelocity().x, mover->GetVelocity().y);
    drag_force.Mult(-1);
    drag_force.SetMag(drag_magnitude);
    return drag_force;
}

void Liquid_2_5::Show(SDL_Framework *framework)
{
    SDL_SetRenderDrawColor(framework->Renderer(), 173, 216, 230, 255);
    SDL_Rect rect = { x_, y_, width_, height_ };
    SDL_RenderFillRect(framework->Renderer(), &rect);
}

// END

