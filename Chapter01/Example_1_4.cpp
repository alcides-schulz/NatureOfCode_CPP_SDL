#include "Example_1_4.h"

bool Example_1_4::UserRender(int elapsed_time)
{
    ClearScreen();

    PVector mouse = PVector((float)MousePosition().x, (float)MousePosition().y);
    PVector center = PVector((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
    mouse.Sub(center);

    int translate_x = WindowWidth() / 2;
    int translate_y = WindowHeight() / 2;

    SDL_SetRenderDrawColor(Renderer(), kColorBlack.r, kColorBlack.g, kColorBlack.b, 255);
    SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);

    // Multiplying a vector! The vector is now half its original size (multiplied by 0.5).
    mouse.Mult(0.5);
    SDL_SetRenderDrawColor(Renderer(), kColorRed.r, kColorRed.g, kColorRed.b, 255);
    SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);

    return true;
}

    
 //END