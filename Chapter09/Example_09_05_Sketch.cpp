#include "Example_09_05_Sketch.h"

namespace nature_of_code_chapter_09_example_05
{
    bool Sketch::Setup(void)
    {
        _world = new World(this, 20);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        _world->Run();
        if (IsMouseButtonClicked(kMouseLeftButton))
            _world->Born();
        if (IsMouseButtonHeld(kMouseLeftButton))
            _world->Born();
        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _world;
    }
}

// END
