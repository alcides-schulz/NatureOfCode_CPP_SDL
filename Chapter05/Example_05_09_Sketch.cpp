#include "Example_05_09_Sketch.h"

namespace nature_of_code_chapter_05_example_09
{
    bool Sketch::Setup(void)
    {
        for (int i = 0; i < 25; i++) {
            _vehicles.push_back(new Vehicle(this, Utils::Random(Width()), Utils::Random(Height())));
        }
        cout << "Hold mouse left button to add more vehicles." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        for (auto vehicle : _vehicles) {
            vehicle->Separate(_vehicles);
            vehicle->Update();
            vehicle->Borders();
            vehicle->Show();
        }
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            _vehicles.push_back(new Vehicle(this, MousePosition().x, MousePosition().y));
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
