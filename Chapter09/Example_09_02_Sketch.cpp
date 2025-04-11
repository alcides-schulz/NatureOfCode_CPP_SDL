#include "Example_09_02_Sketch.h"

namespace nature_of_code_chapter_09_example_02
{
    bool Sketch::Setup(void)
    {
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        return true;
    }

    void Sketch::Cleanup(void)
    {

    }
}

// END
