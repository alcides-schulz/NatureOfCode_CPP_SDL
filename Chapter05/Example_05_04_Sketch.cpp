#include "Example_05_04_Sketch.h"

namespace nature_of_code_chapter_05_example_04
{
    bool Sketch::Setup(void)
    {
        flowfield_ = new FlowField(Width(), Height(), 20);
        for (int i = 0; i < 120; i++) {
            auto vx = (int)Utils::Random((float)Width());
            auto vy = (int)Utils::Random((float)Height());
            auto ms = Utils::Random(2, 5);
            auto mf = Utils::Random(0.1f, 0.5f);
            vehicles_.push_back(new Vehicle(vx, vy, ms, mf));
        }
        debug_ = true;

        cout << "Left-Click to generate a new flow field and Right-Click to show/hide the grid." << endl;

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        for (auto vehicle : vehicles_) {
            vehicle->Follow(flowfield_);
            vehicle->Run(this);
        }
        
        if (IsMouseButtonClicked(kMouseLeftButton)) {
            flowfield_->Init();
        }
        if (IsMouseButtonClicked(kMouseRightButton)) {
            debug_ = !debug_;
        }
        if (debug_) {
            flowfield_->Show(this);
        }

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete flowfield_;
        while (!vehicles_.empty()) {
            delete vehicles_.back();
            vehicles_.pop_back();
        }
    }
}

// END
