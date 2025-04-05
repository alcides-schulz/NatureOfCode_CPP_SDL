#include "Example_08_03_Sketch.h"

namespace nature_of_code_chapter_08_example_03
{
    bool Sketch::Draw(void)
    {
        Background(255);
        DrawCircles(Width() / 2, Height() / 2, 320);
        NoLoop();
        return true;
    }

    void Sketch::DrawCircles(int x, int y, int r)
    {
        Stroke(0);
        Circle(x, y, r * 2);
        if (r > 16) {
            DrawCircles(x + r / 2, y, r / 2);
            DrawCircles(x - r / 2, y, r / 2);
            DrawCircles(x, y + r / 2, r / 2);
            DrawCircles(x, y - r / 2, r / 2);
        }
    }
}

// END
