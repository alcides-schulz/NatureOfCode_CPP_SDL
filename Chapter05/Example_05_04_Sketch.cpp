#include "Example_05_04_Sketch.h"

namespace nature_of_code_chapter_05_example_04
{
    bool Sketch::Setup(void)
    {
        _flowfield = new FlowField(Width(), Height(), 20);
        for (int i = 0; i < 120; i++) {
            auto vx = (int)Utils::Random((float)Width());
            auto vy = (int)Utils::Random((float)Height());
            auto ms = Utils::Random(2, 5);
            auto mf = Utils::Random(0.1f, 0.5f);
            _vehicles.push_back(new Vehicle(vx, vy, ms, mf));
        }
        _debug = true;

        cout << "Left-Click to generate a new flow field and Right-Click to show/hide the grid." << endl;

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        for (auto vehicle : _vehicles) {
            vehicle->Follow(_flowfield);
            vehicle->Run(this);
        }
        
        if (IsMouseButtonClicked(kMouseLeftButton)) {
            _flowfield->Init();
        }
        if (IsMouseButtonClicked(kMouseRightButton)) {
            _debug = !_debug;
        }
        if (_debug) {
            _flowfield->Show(this);
        }

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _flowfield;
        while (!_vehicles.empty()) {
            delete _vehicles.back();
            _vehicles.pop_back();
        }
    }
}

// END
