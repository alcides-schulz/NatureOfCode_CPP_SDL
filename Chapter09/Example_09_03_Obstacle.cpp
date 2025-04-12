#include "Example_09_03_Obstacle.h"

namespace nature_of_code_chapter_09_example_03
{
    Obstacle::Obstacle(P5SDL *p5sdl, int x, int y, int w, int h)
    {
        _p5sdl = p5sdl;
        _position = Vector(x, y);
        _width = w;
        _height = h;
    }

    void Obstacle::Show(void)
    {
        _p5sdl->Stroke(0);
        _p5sdl->Fill(175);
        _p5sdl->StrokeWeight(2);
        _p5sdl->RectMode(kRectCorner);
        _p5sdl->Rect((int)_position.x, (int)_position.y, _width, _height);
    }

    bool Obstacle::Contains(Vector spot)
    {
        return spot.x > _position.x && spot.x < _position.x + _width
            && spot.y > _position.y && spot.y < _position.y + _height;
    }

}

// END
