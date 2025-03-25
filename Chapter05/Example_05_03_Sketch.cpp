#include "Example_05_03_Sketch.h"

namespace nature_of_code_chapter_05_example_03
{
    bool Sketch::Setup(void)
    {
        vehicle_ = new Vehicle(Width() / 2, Height() / 2);
        offset_ = 25;
        debug_ = true;

        cout << "Click to show/hide boundaries." << endl;

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        if (IsMouseButtonClicked(kMouseLeftButton)) {
            debug_ = !debug_;
        }

        if (debug_) {
            Rect(offset_, offset_, Width() - offset_ * 2, Height() - offset_ * 2);
        }

        vehicle_->Boundaries(this, offset_);
        vehicle_->Update();
        vehicle_->Show(this);

        return true;
    }
}

// END
