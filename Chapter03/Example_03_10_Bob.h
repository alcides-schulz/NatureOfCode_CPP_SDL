#ifndef EXAMPLE_03_10_BOB_H
#define EXAMPLE_03_10_BOB_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_03_example_10
{
    class Bob
    {
    public:
        Bob(Vector position) : _position(position)
        {
            _velocity = Vector(0, 0);
            _acceleration = Vector(0, 0);
            _mass = 24;
            _damping = 0.98f;
            _drag_offset = Vector(0, 0);
            _is_dragging = false;
        };
        void ApplyForce(Vector force);
        void Update(P5SDL *p5sdl);
        void Show(P5SDL *p5sdl);
        Vector GetPosition(void) { return _position; };
        void SetPosition(Vector position) { _position = position; };
        Vector GetVelocity(void) { return _velocity; };
        void SetVelocity(Vector velocity) { _velocity = velocity; };
        void HandleClick(int mouse_x, int mouse_y);
        void HandleDrag(int mouse_x, int mouse_y);
        void StopDragging(void);
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        float   _mass;
        float   _damping;
        Vector  _drag_offset;
        bool    _is_dragging;
    };
}

#endif
