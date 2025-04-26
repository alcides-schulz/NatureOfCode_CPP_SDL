#include "Button.h"

Button::Button(P5SDL *p5sdl, string label, int x, int y, int w, int h)
{
    _p5sdl = p5sdl;
    _label = label;
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    _text_x = _x + (_w - _p5sdl->TextWidth(_label)) / 2;
    _text_y = _y + (_h - _p5sdl->TextHeight(_label)) / 2;
}

bool Button::Contains(int px, int py)
{
    return px > _x && px < _x + _w && py > _y && py < _y + _h;
}

bool Button::Clicked(void)
{
    if (!_p5sdl->IsMouseButtonClicked(kMouseLeftButton))
        return false;
    if (Contains(_p5sdl->MousePosition().x, _p5sdl->MousePosition().y)) {
        _clicked = true;
        return true;
    }
    return false;
}

void Button::Show(void)
{
    _p5sdl->Stroke(0);
    _p5sdl->StrokeWeight(2);
    if (_clicked)
        _p5sdl->Fill(127), _clicked = false;
    else
        _p5sdl->Fill(255);
    _p5sdl->RectMode(kRectCorner);
    _p5sdl->Rect(_x, _y, _w, _h);
    _p5sdl->Fill(0);
    _p5sdl->Text(_label, _text_x, _text_y);
}

// END
