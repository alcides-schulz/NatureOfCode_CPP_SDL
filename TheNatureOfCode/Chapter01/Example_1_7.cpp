#include "Example_1_7.h"

bool Example_1_7::UserInit()
{
    srand((unsigned int)time(NULL));
    PVector location((float)(rand() % WindowWidth()), (float)(rand() % WindowHeight()));
    PVector velocity((float)(rand() % 8 - 4), (float)(rand() % 8 - 4));
    mover = new Chapter01Mover(this, location, velocity);
    return true;
}

bool Example_1_7::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());
    mover->Update();
    mover->CheckEdges();
    mover->Display();
    return true;
}

//END
