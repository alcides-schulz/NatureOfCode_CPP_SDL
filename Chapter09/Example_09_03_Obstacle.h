#ifndef EXAMPLE_09_03_OBSTACLE_H
#define EXAMPLE_09_03_OBSTACLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_09_example_03
{
    class Obstacle
    {
    public:
        Obstacle(P5SDL *p5sdl, int x, int y, int w, int h);
        void Show(void);
        bool Contains(Vector spot);
        Vector GetPosition(void) { return _position; };
        void SetPosition(Vector position) { _position = position; };
    private:
        P5SDL *_p5sdl;
        Vector _position;
        int _width;
        int _height;
    };
}

#endif
