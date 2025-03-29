#include "Example_05_07_Sketch.h"

namespace nature_of_code_chapter_05_example_07
{
    bool Sketch::Setup(void)
    {
        _path = new Path();
        _path->AddPoint(-20, Height() / 2);
        _path->AddPoint(100, 50);
        _path->AddPoint(400, 200);
        _path->AddPoint(Width() + 20, Height() / 2);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        _path->Show(this);
        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _path;
    }
}

// END
