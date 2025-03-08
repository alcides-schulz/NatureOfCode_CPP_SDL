#include "Example_1_10.h"

bool Example_1_10::UserInit()
{
    PVector location((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
    PVector velocity(0, 0);
    mover_ = new Mover_1_10(location, velocity);
    return true;
}

bool Example_1_10::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    PVector mouse = PVector((float)MousePosition().x, (float)MousePosition().y);
    PVector direction = PVector(mouse.x, mouse.y);
    direction.Sub(mover_->GetLocation());
    direction.Normalize();
    direction.Mult(0.2f);
    
    mover_->SetAcceleration(direction);
    mover_->Update();
    mover_->CheckEdges(this);
    mover_->Display(this);

    return true;
}

// END
