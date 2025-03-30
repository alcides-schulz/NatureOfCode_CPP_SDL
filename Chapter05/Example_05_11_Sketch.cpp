#include "Example_05_11_Sketch.h"

namespace nature_of_code_chapter_05_example_11
{
    bool Sketch::Setup(void)
    {
        _flock = new Flock();
        for (int i = 0; i < 120; i++) {
            auto boid = new Boid(this, Width() / 2, Height() / 2);
            _flock->AddBoid(boid);
        }
        cout << "Drag mouse to add more boids." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        _flock->Run();
        if (IsMouseButtonHeld(kMouseLeftButton))
            _flock->AddBoid(new Boid(this, MousePosition().x, MousePosition().y));
        return true;
    }

    void Sketch::Cleanup(void)
    {
        _flock->Cleanup();
        delete _flock;
    }
}

// END
