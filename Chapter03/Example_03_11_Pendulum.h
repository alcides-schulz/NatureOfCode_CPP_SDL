#ifndef EXAMPLE_03_11_PENDULUM_H
#define EXAMPLE_03_11_PENDULUM_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_03_example_11
{
    class Pendulum
    {
    public:
        Pendulum(int x, int y, float r)
        {
            pivot_ = PVector(x, y);
            bob_ = PVector(0, 0);
            r_ = r;
            angle_ = (float)(M_PI / 4);
            angle_velocity_ = 0;
            angle_acceleration_ = 0;
            damping_ = 0.995f;
            ball_r_ = 24.0f;
            is_dragging_ = false;
        };
        void Update(void);
        void Show(SDL_Framework *framework);
        void HandleClick(int mouse_x, int mouse_y);
        void HandleDrag(int mouse_x, int mouse_y);
        void StopDragging(void);
    private:
        PVector pivot_;
        PVector bob_;
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
