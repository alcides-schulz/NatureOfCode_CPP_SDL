#include "Example_05_10_Sketch.h"

namespace nature_of_code_chapter_05_example_10
{
    bool Sketch::Setup(void)
    {
        for (int i = 0; i < 50; i++) {
            _vehicles.push_back(new Vehicle(this, Utils::Random(Width()), Utils::Random(Height())));
        }
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        for (auto vehicle : _vehicles) {
            vehicle->ApplyBehaviors(_vehicles);
            vehicle->Update();
            vehicle->Borders();
            vehicle->Show();
        }
        return true;
    }

    void Sketch::Cleanup(void)
    {
        while (!_vehicles.empty()) {
            delete _vehicles.back();
            _vehicles.pop_back();
        }
    }
}

// END
