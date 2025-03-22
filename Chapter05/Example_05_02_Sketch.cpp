#include "Example_05_02_Sketch.h"

namespace nature_of_code_chapter_05_example_02
{
    bool Sketch::Setup(void)
    {
        vehicle_ = new Vehicle(Width() / 2, Height() / 2);
        return true;
    }

    bool Sketch::Draw(void)
    {
        ClearScreen();

        auto mouse = PVector(MousePosition().x, MousePosition().y);
        DrawCircle(mouse.x, mouse.y, 48, kColorGray, true);

        vehicle_->Arrive(mouse);
        vehicle_->Update();
        vehicle_->Show(this);

        return true;
    }
}

// END
