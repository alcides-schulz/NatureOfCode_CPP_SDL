#include "Example_01_05_Sketch.h"

namespace nature_of_code_chapter_01_example_05
{
    bool Sketch::Draw()
    {
        Background(255);
    
        auto mouse = Vector(MousePosition().x, MousePosition().y);
        auto center = Vector(Width() / 2, Height() / 2);
    
        mouse.Sub(center);
        auto magnitude = (int) mouse.Mag();
    
        SDL_SetRenderDrawColor(Renderer(), kColorBlack.r, kColorBlack.g, kColorBlack.b, kColorBlack.a);
        SDL_Rect rect = { 0, 0, magnitude, 10 };
        SDL_RenderFillRect(Renderer(), &rect);
    
        Translate(Width() / 2, Height() / 2);
        Stroke(kColorBlack);
        Line(0, 0, (int)mouse.x, (int)mouse.y);
    
        return true;
    }
    
}

// END
