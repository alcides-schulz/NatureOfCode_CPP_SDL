#include "Example_02_06_Sketch.h"

namespace nature_of_code_chapter_02_example_06
{
    bool Sketch::Setup()
    {
        _mover = new Mover(Vector(300, 50), 2);
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
    
        Vector force = _attractor->Attract(_mover);
        _mover->ApplyForce(force);
        _mover->Update();
        _mover->Show(this);
    
        return true;
    }
    
}

// END
