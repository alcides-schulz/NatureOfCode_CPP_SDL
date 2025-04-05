#include "Example_08_02_Sketch.h"

namespace nature_of_code_chapter_08_example_02
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
        if (r > 4) {
            DrawCircles(x + r / 2, y, r / 2);
            DrawCircles(x - r / 2, y, r / 2);
        }
    }
}

// END
