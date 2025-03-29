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
            pivot_ = Vector(x, y);
            bob_ = Vector(0, 0);
            r_ = r;
            angle_ = (float)(M_PI / 4);
            angle_velocity_ = 0;
            angle_acceleration_ = 0;
            damping_ = 0.995f;
            ball_r_ = 24.0f;
            is_dragging_ = false;
        };
        void Update(void);
        void Show(P5SDL *p5sdl);
        void HandleClick(int mouse_x, int mouse_y);
        void HandleDrag(int mouse_x, int mouse_y);
        void StopDragging(void);
    private:
        Vector pivot_;
        Vector bob_;
        float   r_;
        float   angle_;
        float   angle_velocity_;
        float   angle_acceleration_;
        float   damping_;
        float   ball_r_;
        bool    is_dragging_;
    };
}

#endif
