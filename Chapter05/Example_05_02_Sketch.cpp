#include "Example_05_02_Sketch.h"

namespace nature_of_code_chapter_05_example_02
{
    bool Sketch::Setup(void)
    {
        _vehicle = new Vehicle(Width() / 2, Height() / 2);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        auto mouse = Vector(MousePosition().x, MousePosition().y);
        Stroke(0);
        Fill(127);
        Circle(mouse.x, mouse.y, 48);

        _vehicle->Arrive(mouse);
        _vehicle->Update();
        _vehicle->Show(this);

        return true;
    }
}

// END
