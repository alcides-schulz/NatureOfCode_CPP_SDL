#include "../../SDL_Framework.h"
#include "../Common/PVector.h"

class Example_1_5 : public SDL_Framework
{
public:
    Example_1_5() :
        SDL_Framework("Example 1.5: Vector Magnitude", 400, 100, 1200, 800, 0) {}

    bool UserRender(int elapsed_time) override
    {
        SDL_SetRenderDrawColor(Renderer(), 255, 255, 255, 255);
        SDL_RenderClear(Renderer());
        PVector mouse = PVector((float)MousePosition().x, (float)MousePosition().y);
        PVector center = PVector((float)(WindowWidth() / 2), (float)(WindowHeight() / 2));
        mouse.Sub(center);
        float magnitude = mouse.Mag();
        SDL_SetRenderDrawColor(Renderer(), 0, 0, 0, 255);
        SDL_Rect rect = { 0, 0, (int)magnitude, 10 };
        SDL_RenderFillRect(Renderer(), &rect);
        int translate_x = WindowWidth() / 2;
        int translate_y = WindowHeight() / 2;
        SDL_RenderDrawLine(Renderer(), translate_x, translate_y, (int)mouse.x + translate_x, (int)mouse.y + translate_y);
        return true;
    }
};

SDL_Framework *GetInstanceExample_1_5()
{
    return new Example_1_5();
}

// END
