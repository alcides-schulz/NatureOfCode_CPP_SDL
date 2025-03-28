#include "Example_05_07_Sketch.h"

namespace nature_of_code_chapter_05_example_07
{
    bool Sketch::Setup(void)
    {
        path_ = new Path();
        path_->AddPoint(-20, Height() / 2);
        path_->AddPoint(100, 50);
        path_->AddPoint(400, 200);
        path_->AddPoint(Width() + 20, Height() / 2);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        path_->Show(this);
        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete path_;
    }
}

// END
