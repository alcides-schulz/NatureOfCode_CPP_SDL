#include "Example_03_02_Sketch.h"
#include "../Common/Utils.h"
namespace nature_of_code_chapter_03_example_02
{
    
    bool Sketch::Setup()
    {
        for (int i = 0; i < std::size(_mover); i++) {
            auto x = Utils::Random((float)Width());
            auto y = Utils::Random((float)Height());
            auto m = (int)Utils::Random(1.0f, 4.0f);
            _mover[i] = new Mover(Vector(x, y), m);
            auto vx = Utils::Random(-1, 1);
            auto vy = Utils::Random(-1, 1);
            _mover[i]->SetVelocity(Vector(vx, vy));
        }
        _attractor = new Attractor(Vector(Width() / 2.0f, Height() / 2.0f), 20);
        return true;
    }
    
    bool Sketch::Draw()
    {
        Background(255);
    
        if (!_is_dragging && IsMouseButtonHeld(kMouseLeftButton)) {
            auto mouse_position = Vector((float)MousePosition().x, (float)MousePosition().y);
            auto distance = Vector::Distance(mouse_position, _attractor->GetPosition());
            if (distance <= _attractor->GetRadius()) {
                _is_dragging = true;
            }
        }
        if (_is_dragging && IsMouseButtonHeld(kMouseLeftButton)) {
            _attractor->SetPosition(Vector((float)MousePosition().x, (float)MousePosition().y));
        }
        if (!IsMouseButtonHeld(kMouseLeftButton)) {
            _is_dragging = false;
        }
    
        _attractor->Show(this);
    
        for (int i = 0; i < std::size(_mover); i++) {
            Vector force = _attractor->Attract(_mover[i]);
            _mover[i]->ApplyForce(force);
            _mover[i]->Update();
            _mover[i]->Show(this);
        }
    
        return true;
    }
    
}

// END
