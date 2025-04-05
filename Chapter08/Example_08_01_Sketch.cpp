#include "Example_08_01_Sketch.h"

namespace nature_of_code_chapter_08_example_01
{
    bool Sketch::Draw(void)
    {
        Background(255);
        DrawCircles(Width() / 2, Height() / 2, Width() / 2);
        NoLoop();
        return true;
    }

    void Sketch::DrawCircles(int x, int y, int r)
    {
        Stroke(0);
        Circle(x, y, r * 2);
        if (r > 4) {
            r = (int)(r * 0.75);
            DrawCircles(x, y, r);
        }
    }
}

// END
