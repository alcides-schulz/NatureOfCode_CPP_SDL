#include "Example_1_3.h"

bool Example_1_3::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    auto mouse = PVector((float)MousePosition().x, (float)MousePosition().y);
    auto center = PVector((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));

    SDL_SetRenderDrawColor(Renderer(), kColorBlack.r, kColorBlack.g, kColorBlack.b, 255);
    SDL_RenderDrawLine(Renderer(), 0, 0, (int)mouse.x, (int)mouse.y);
    SDL_RenderDrawLine(Renderer(), 0, 0, (int)center.x, (int)center.y);

    mouse.Sub(center);

    // Draw a line to represent the result of subtraction.
    // Simulate translate() method to draw the line from center of window to new vector location.
    int translate_x = WindowWidth() / 2;
    int translate_y = WindowHeight() / 2;
    SDL_SetRenderDrawColor(Renderer(), kColorRed.r, kColorRed.g, kColorRed.b, 255);
    SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);

    return true;
}

//END