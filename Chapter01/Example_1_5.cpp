#include "Example_1_5.h"

bool Example_1_5::UserRender(int elapsed_time)
{
    ClearScreen();

    // The magnitude (i.e. length) of a vector can be accessed via the mag() function.
    // Here it is used as the width of a rectangle drawn at the top of the window.
    PVector mouse = PVector((float)MousePosition().x, (float)MousePosition().y);
    PVector center = PVector((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
    mouse.Sub(center);
    float magnitude = mouse.Mag();

    SDL_Rect rect = { 0, 0, (int)magnitude, 10 };
    SDL_SetRenderDrawColor(Renderer(), kColorBlack.r, kColorBlack.g, kColorBlack.b, 255);
    SDL_RenderFillRect(Renderer(), &rect);

    int translate_x = WindowWidth() / 2;
    int translate_y = WindowHeight() / 2;

    SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);

    return true;
}

// END
