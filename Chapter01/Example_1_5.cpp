#include "Example_1_5.h"

bool Example_1_5::UserRender(int elapsed_time)
{
    ClearScreen();

    auto mouse = PVector(MousePosition().x, MousePosition().y);
    auto center = PVector(WindowWidth() / 2, WindowHeight() / 2);

    mouse.Sub(center);
    auto magnitude = (int) mouse.Mag();

    SDL_SetRenderDrawColor(Renderer(), kColorBlack.r, kColorBlack.g, kColorBlack.b, kColorBlack.a);
    SDL_Rect rect = { 0, 0, magnitude, 10 };
    SDL_RenderFillRect(Renderer(), &rect);

    Translate(WindowWidth() / 2, WindowHeight() / 2);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);

    return true;
}

// END
