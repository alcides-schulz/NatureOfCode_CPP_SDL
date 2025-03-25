#include "Example_05_05_Sketch.h"

namespace nature_of_code_chapter_05_example_05
{
    bool Sketch::Setup(void)
    {
        path_ = new Path(this);
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
