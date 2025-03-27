#include "Example_05_06_Sketch.h"

namespace nature_of_code_chapter_05_example_06
{
    bool Sketch::Setup(void)
    {
        path_ = new Path(this);
        vehicle1_ = new Vehicle(0, Height() / 2, 2.0f, 0.02f);
        vehicle2_ = new Vehicle(0, Height() / 2, 3.0f, 0.02f);
        debug_ = true;
        cout << "Click to turn debug on/off." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        path_->Show(this);
        vehicle1_->Follow(path_, this, debug_);
        vehicle2_->Follow(path_, this, debug_);

        vehicle1_->Run(this);
        vehicle2_->Run(this);

        vehicle1_->Borders(path_);
        vehicle2_->Borders(path_);

        if (IsMouseButtonClicked(kMouseLeftButton))
            debug_ = !debug_;

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete path_;
    }
}

// END
