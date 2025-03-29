#include "Example_05_08_Sketch.h"

namespace nature_of_code_chapter_05_example_08
{
    bool Sketch::Setup(void)
    {
        path_ = nullptr;
        NewPath();
        car1_ = new Vehicle(0, Height() / 2, 2, 0.04f);
        car2_ = new Vehicle(0, Height() / 2, 3, 0.1f);
        debug_ = true;
        cout << "Left-Click for debug on/off and Right-Click for a new path." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        
        path_->Show(this);

        car1_->Follow(path_, this, debug_);
        car2_->Follow(path_, this, debug_);
        car1_->Run(this);
        car2_->Run(this);
        car1_->Borders(path_);
        car2_->Borders(path_);

        if (IsMouseButtonClicked(kMouseLeftButton)) {
            debug_ = !debug_;
        }

        if (IsMouseButtonClicked(kMouseRightButton)) {
            NewPath();
        }

        return true;
    }

    void Sketch::NewPath(void)
    {
        if (path_ != nullptr) {
            delete path_;
        }
        path_ = new Path();
        path_->AddPoint(-20.0f, Height() / 2.0f);
        path_->AddPoint(Utils::Random(0.0f, Width() / 2.0f), Utils::Random(0.0f, (float)Height()));
        path_->AddPoint(Utils::Random(Width() / 2.0f, (float)Width()), Utils::Random(0, (float)Height()));
        path_->AddPoint(Width() + 20.0f, Height() / 2.0f);
    }

    void Sketch::Cleanup(void)
    {
        delete path_;
        delete car1_;
        delete car2_;
    }
}

// END
