#include "Example_2_9.h"

#include <cstdlib>
#include <ctime>

bool Example_2_9::UserInit()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < std::size(body_); i++) {
        auto x = (float)(std::rand() % WindowWidth());
        auto y = (float)(std::rand() % WindowHeight());
        auto m = std::rand() % 5 + 1;
        body_[i] = new Body(PVector(x, y), m);
    }
    return true;
}

bool Example_2_9::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
    SDL_RenderClear(Renderer());

    for (int i = 0; i < std::size(body_); i++) {
        for (int j = 0; j < std::size(body_); j++) {
            if (i == j)
                continue;
            body_[i]->Attract(body_[j]);
        }
    }
    for (int i = 0; i < std::size(body_); i++) {
        body_[i]->Update();
        body_[i]->Display(this);
    }

    return true;
}

// END