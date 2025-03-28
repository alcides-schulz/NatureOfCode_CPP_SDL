#ifndef EXAMPLE_03_10_BOB_H
#define EXAMPLE_03_10_BOB_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_10
{
    class Bob
    {
    public:
        Bob(Vector position) : position_(position)
        {
            velocity_ = Vector(0, 0);
            acceleration_ = Vector(0, 0);
            mass_ = 24;
            damping_ = 0.98f;
            drag_offset_ = Vector(0, 0);
            is_dragging_ = false;
        };
        void ApplyForce(Vector force);
        void Update(SDL_Framework *framework);
        void Show(SDL_Framework *framework);
        Vector GetPosition(void) { return position_; };
        void SetPosition(Vector position) { position_ = position; };
        Vector GetVelocity(void) { return velocity_; };
        void SetVelocity(Vector velocity) { velocity_ = velocity; };
        void HandleClick(int mouse_x, int mouse_y);
        void HandleDrag(int mouse_x, int mouse_y);
        void StopDragging(void);
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        float   mass_;
        float   damping_;
        Vector drag_offset_;
        bool    is_dragging_;
    };
}

#endif
