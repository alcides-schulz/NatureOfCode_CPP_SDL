#include "Example_1_5.h"

bool Example_1_5::Draw()
{
    ClearScreen();

    auto mouse = PVector(MousePosition().x, MousePosition().y);
    auto center = PVector(Width() / 2, Height() / 2);

    mouse.Sub(center);
    auto magnitude = (int) mouse.Mag();

    SDL_SetRenderDrawColor(Renderer(), kColorBlack.r, kColorBlack.g, kColorBlack.b, kColorBlack.a);
    SDL_Rect rect = { 0, 0, magnitude, 10 };
    SDL_RenderFillRect(Renderer(), &rect);

    Translate(Width() / 2, Height() / 2);
    DrawLine(0, 0, (int)mouse.x, (int)mouse.y, kColorBlack);

    return true;
}

// END
