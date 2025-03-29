#include "Example_01_07_Mover.h"

namespace nature_of_code_chapter_01_example_07
{
    void Mover::Update(void)
    {
        _position.Add(_velocity);
    }
    
    void Mover::Show(P5SDL *p5sdl)
    {
        p5sdl->Stroke(0);
        p5sdl->Fill(127);
        p5sdl->Circle(_position.x, _position.y, 48);
    }
    
    void Mover::CheckEdges(P5SDL *p5sdl)
    {
        if (_position.x > p5sdl->Width())
            _position.x = 0;
        else if (_position.x < 0)
            _position.x = (float)p5sdl->Width();
        if (_position.y > p5sdl->Height())
            _position.y = 0;
        else if (_position.y < 0)
            _position.y = (float)p5sdl->Height();
    }
    
}

// END
