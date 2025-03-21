#ifndef EXAMPLE_03_10_BOB_H
#define EXAMPLE_03_10_BOB_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_03_example_10
{
    class Bob
    {
    public:
        Bob(PVector position) : position_(position)
        {
            velocity_ = PVector(0, 0);
            acceleration_ = PVector(0, 0);
            mass_ = 24;
            damping_ = 0.98f;
            drag_offset_ = PVector(0, 0);
            is_dragging_ = false;
        };
        void ApplyForce(PVector force);
        void Update(SDL_Framework *framework);
        void Show(SDL_Framework *framework);
        PVector GetPosition(void) { return position_; };
        void SetPosition(PVector position) { position_ = position; };
        PVector GetVelocity(void) { return velocity_; };
        void SetVelocity(PVector velocity) { velocity_ = velocity; };
        void HandleClick(int mouse_x, int mouse_y);
        void HandleDrag(int mouse_x, int mouse_y);
        void StopDragging(void);
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        float   mass_;
        float   damping_;
        PVector drag_offset_;
        bool    is_dragging_;
    };
}

#endif
