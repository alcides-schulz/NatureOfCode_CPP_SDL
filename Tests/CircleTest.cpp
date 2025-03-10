#include "CircleTest.h"

bool CircleTest::UserRender(int elapsed_time)
{
    SDL_SetRenderDrawColor(Renderer(), kColorWhite.r, kColorWhite.g, kColorWhite.b, 255);
    SDL_RenderClear(Renderer());

    DrawCircle({ 50, 50 }, 100, kColorGray, true);

    return true;
}