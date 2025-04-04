#ifndef EXAMPLE_04_03_PARTICLE_H
#define EXAMPLE_04_03_PARTICLE_H

#include "../Common/Vector.h"
#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_04_example_03
{
    class Particle
    {
    public:
        Particle(int x, int y)
        {
            _position = Vector(x, y);
            _velocity = Vector(Utils::Random(-1, 1), Utils::Random(-2, 0));
            _acceleration = Vector(0, 0);
            _life_span = 255;
        };
        void Update(void);
        void Show(P5SDL *p5sdl);
        void ApplyForce(Vector force);
        bool IsDead(void) { return _life_span <= 0; };
        void Run(P5SDL *p5sdl);
    private:
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        Uint8   _life_span;
    };
}

#endif
