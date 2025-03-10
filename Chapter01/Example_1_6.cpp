#include "Example_1_6.h"

bool Example_1_6::UserRender(int elapsed_time)
{
    ClearScreen();

    // Subtract center from mouse which results in a vector that points from center to mouse
    PVector mouse = PVector((float)MousePosition().x, (float)MousePosition().y);
    PVector center = PVector((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
    mouse.Sub(center);
    int translate_x = WindowWidth() / 2;
    int translate_y = WindowHeight() / 2;
    SDL_SetRenderDrawColor(Renderer(), 0, 0, 0, 255);
    SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);

    // Normalize the vector and draw the vector
    mouse.Normalize();
    mouse.Mult(50);
    SDL_SetRenderDrawColor(Renderer(), 255, 0, 0, 255);
    SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);

    return true;
}

// END
