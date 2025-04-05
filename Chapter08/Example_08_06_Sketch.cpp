#include "Example_08_06_Sketch.h"

namespace nature_of_code_chapter_08_example_06
{
    bool Sketch::Setup(void)
    {
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        _angle = Utils::Map(MousePosition().x, 0, Width(), 0, M_PI / 2);
        Translate(Width() / 2, Height());
        Stroke(0);
        StrokeWeight(2);
        Branch(80);

        return true;
    }

    void Sketch::Branch(int length)
    {
        Line(0, 0, 0, -length);
        Translate(0, -length);

        length = (int)(length * 0.67);

        if (length > 2) {
            Push();
            Rotate(_angle);
            Branch(length);
            Pop();

            Push();
            Rotate(-_angle);
            Branch(length);
            Pop();
        }
    }
}

// END
