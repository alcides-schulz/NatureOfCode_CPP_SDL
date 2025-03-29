#include "Example_05_06_Sketch.h"

namespace nature_of_code_chapter_05_example_06
{
    bool Sketch::Setup(void)
    {
        _path = new Path(this);
        _vehicle1 = new Vehicle(0, Height() / 2, 2.0f, 0.02f);
        _vehicle2 = new Vehicle(0, Height() / 2, 3.0f, 0.02f);
        _debug = true;
        cout << "Click to turn debug on/off." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        _path->Show(this);
        _vehicle1->Follow(_path, this, _debug);
        _vehicle2->Follow(_path, this, _debug);

        _vehicle1->Run(this);
        _vehicle2->Run(this);

        _vehicle1->Borders(_path);
        _vehicle2->Borders(_path);

        if (IsMouseButtonClicked(kMouseLeftButton))
            _debug = !_debug;

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _path;
    }
}

// END
