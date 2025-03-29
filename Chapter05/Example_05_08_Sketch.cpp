#include "Example_05_08_Sketch.h"

namespace nature_of_code_chapter_05_example_08
{
    bool Sketch::Setup(void)
    {
        _path = nullptr;
        NewPath();
        _car1 = new Vehicle(0, Height() / 2, 2, 0.04f);
        _car2 = new Vehicle(0, Height() / 2, 3, 0.1f);
        _debug = true;
        cout << "Left-Click for debug on/off and Right-Click for a new path." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        
        _path->Show(this);

        _car1->Follow(_path, this, _debug);
        _car2->Follow(_path, this, _debug);
        _car1->Run(this);
        _car2->Run(this);
        _car1->Borders(_path);
        _car2->Borders(_path);

        if (IsMouseButtonClicked(kMouseLeftButton)) {
            _debug = !_debug;
        }

        if (IsMouseButtonClicked(kMouseRightButton)) {
            NewPath();
        }

        return true;
    }

    void Sketch::NewPath(void)
    {
        if (_path != nullptr) {
            delete _path;
        }
        _path = new Path();
        _path->AddPoint(-20.0f, Height() / 2.0f);
        _path->AddPoint(Utils::Random(0.0f, Width() / 2.0f), Utils::Random(0.0f, (float)Height()));
        _path->AddPoint(Utils::Random(Width() / 2.0f, (float)Width()), Utils::Random(0, (float)Height()));
        _path->AddPoint(Width() + 20.0f, Height() / 2.0f);
    }

    void Sketch::Cleanup(void)
    {
        delete _path;
        delete _car1;
        delete _car2;
    }
}

// END
