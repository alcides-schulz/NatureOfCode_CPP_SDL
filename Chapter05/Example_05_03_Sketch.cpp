#include "Example_05_03_Sketch.h"

namespace nature_of_code_chapter_05_example_03
{
    bool Sketch::Setup(void)
    {
        _vehicle = new Vehicle(Width() / 2, Height() / 2);
        _offset = 25;
        _debug = true;

        cout << "Click to show/hide boundaries." << endl;

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        if (IsMouseButtonClicked(kMouseLeftButton)) {
            _debug = !_debug;
        }

        if (_debug) {
            Rect(_offset, _offset, Width() - _offset * 2, Height() - _offset * 2);
        }

        _vehicle->Boundaries(this, _offset);
        _vehicle->Update();
        _vehicle->Show(this);

        return true;
    }
}

// END
