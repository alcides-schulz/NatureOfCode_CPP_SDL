#ifndef BUTTON_H
#define BUTTON_H

#include "../Common/P5SDL.h"

class Button
{
public:
    Button(P5SDL *p5sdl, string label, int x, int y, int w, int h);
    bool Contains(int px, int py);
    void Show(void);
    bool Clicked(void);
private:
    P5SDL *_p5sdl;
    string _label;
    int _x;
    int _y;
    int _w;
    int _h;
    int _text_x;
    int _text_y;
    bool _clicked = false;
};

#endif
