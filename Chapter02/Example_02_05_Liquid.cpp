#include "Example_02_05_Liquid.h"

namespace nature_of_code_chapter_02_example_05
{
    bool Liquid::Contains(Mover *mover)
    {
        Vector& loc = mover->GetPosition();
        return loc.x > _x && loc.x < _x + _width && loc.y > _y && loc.y + _y + _height;
    }
    
    Vector Liquid::CalculateDrag(Mover *mover)
    {
        float speed = mover->GetVelocity().Mag();
        float drag_magnitude = _drag_coef * speed * speed;
        Vector drag_force = Vector(mover->GetVelocity().x, mover->GetVelocity().y);
        drag_force.Mult(-1);
        drag_force.SetMag(drag_magnitude);
        return drag_force;
    }
    
    void Liquid::Show(P5SDL *p5sdl)
    {
        SDL_SetRenderDrawColor(p5sdl->Renderer(), 173, 216, 230, 255);
        SDL_Rect rect = { _x, _y, _width, _height };
        SDL_RenderFillRect(p5sdl->Renderer(), &rect);
    }
    
}

// END
