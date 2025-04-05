#include "Example_08_07_Sketch.h"

namespace nature_of_code_chapter_08_example_07
{
    bool Sketch::Setup(void)
    {
        FrameRate(1);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        Stroke(0);
        StrokeWeight(2);
     
        Push();
        Translate(Width() / 2, Height());
        Branch(80);
        Pop();

        return true;
    }

    void Sketch::Branch(int length)
    {
        Line(0, 0, 0, -length);
        Translate(0, -length);

        length = (int)(length * 0.67);

        if (length > 2) {
            auto n = floor(Utils::Random(1, 4));
            for (int i = 0; i < n; i++) {
                auto angle = Utils::Random((float)(-M_PI / 2), (float)(M_PI / 2));
                Push();
                Rotate(angle);
                Branch(length);
                Pop();
            }
        }
    }
}

// END
