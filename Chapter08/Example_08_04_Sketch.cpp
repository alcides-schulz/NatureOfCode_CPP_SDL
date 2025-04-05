#include "Example_08_04_Sketch.h"

namespace nature_of_code_chapter_08_example_04
{
    bool Sketch::Setup(void)
    {
        Background(255);
        StrokeWeight(2);
        Cantor(10, 70, 620);
        return true;
    }

    bool Sketch::Draw(void)
    {
        NoLoop();
        return true;
    }

    void Sketch::Cantor(int x, int y, int length)
    {
        if (length > 1) {
            Line(x, y, x + length, y);
            Cantor(x, y + 20, length / 3);
            Cantor(x + (2 * length) / 3, y + 20, length / 3);
        }
    }
}

// END
