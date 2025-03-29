#ifndef EXAMPLE_03_11_PENDULUM_H
#define EXAMPLE_03_11_PENDULUM_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_11
{
    class Pendulum
    {
    public:
        Pendulum(int x, int y, float r)
        {
            _pivot = Vector(x, y);
            _bob = Vector(0, 0);
            _r = r;
            _angle = (float)(M_PI / 4);
            _angle_velocity = 0;
            _angle_acceleration = 0;
            _damping = 0.995f;
            _ball_r = 24.0f;
            _is_dragging = false;
        };
        void Update(void);
        void Show(P5SDL *p5sdl);
        void HandleClick(int mouse_x, int mouse_y);
        void HandleDrag(int mouse_x, int mouse_y);
        void StopDragging(void);
    private:
        Vector  _pivot;
        Vector  _bob;
        float   _r;
        float   _angle;
        float   _angle_velocity;
        float   _angle_acceleration;
        float   _damping;
        float   _ball_r;
        bool    _is_dragging;
    };
}

#endif
