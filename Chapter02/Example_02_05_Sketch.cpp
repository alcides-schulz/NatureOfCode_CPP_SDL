#include "Example_02_05_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_02_example_05
{
    
    bool Sketch::Setup()
    {
        _liquid = new Liquid(0, Height() / 2, Width(), Height() / 2, 0.1f);
        for (int i = 0; i < std::size(_mover); i++) {
            _mover[i] = nullptr;
        }
        Reset();
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        if (IsMouseButtonHeld(kMouseLeftButton)) {
            Reset();
        }
        _liquid->Show(this);
        for (int i = 0; i < std::size(_mover); i++) {
            if (_liquid->Contains(_mover[i])) {
                auto dragForce = _liquid->CalculateDrag(_mover[i]);
                _mover[i]->ApplyForce(dragForce);
            }
            Vector gravity(0.0f, 0.1f);
            gravity.Mult((float)_mover[i]->GetMass());
            _mover[i]->ApplyForce(gravity);
            _mover[i]->Update();
            _mover[i]->CheckEdges(this);
            _mover[i]->Show(this);
        }
    
        return true;
    }
    
    void Sketch::Reset(void)
    {
        for (int i = 0; i < std::size(_mover); i++) {
            if (_mover[i] != nullptr) {
                delete _mover[i];
            }
            _mover[i] = new Mover(Vector(40 + i * 70, 0), (int)(Utils::Random(1, 4)));
        }
    }
    
}

// END
