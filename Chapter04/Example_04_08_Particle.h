#ifndef EXAMPLE_04_08_PARTICLE_H
#define EXAMPLE_04_08_PARTICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_04_example_08
{
    class Particle
    {
    public:
        Particle(int x, int y, SDL_Texture *texture)
        {
            _position = Vector(x, y);
            _texture = texture;
            auto vx = Utils::Random(0.0f, 0.3f);
            auto vy = Utils::Random(-1.0f, 0.3f);
            _velocity = Vector(vx, vy);
            _acceleration = Vector(0, 0);
            _life_span = 100.0f;
        };
        void Update(void);
        virtual void Show(P5SDL *p5sdl);
        void ApplyForce(Vector force);
        bool IsDead(void) { return _life_span <= 0; };
        void Run(P5SDL *p5sdl);
    protected:
        Vector      _position;
        SDL_Texture *_texture;
        Vector      _velocity;
        Vector      _acceleration;
        float       _life_span;
    };
}

#endif
