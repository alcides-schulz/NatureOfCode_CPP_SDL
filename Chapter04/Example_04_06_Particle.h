#ifndef EXAMPLE_04_06_PARTICLE_H
#define EXAMPLE_04_06_PARTICLE_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_04_example_06
{
    class Particle
    {
    public:
        Particle(int x, int y)
        {
            position_ = Vector(x, y);
            velocity_ = Vector(Utils::Random(-1, 1), Utils::Random(-2, 0));
            acceleration_ = Vector(0, 0);
            life_span_ = 255.0f;
            mass_ = 1.0f;
        };
        void Update(void);
        virtual void Show(P5SDL *p5sdl);
        void ApplyForce(Vector force);
        bool IsDead(void) { return life_span_ < 0; };
        void Run(P5SDL *p5sdl);
    protected:
        Vector     position_;
        Vector     velocity_;
        Vector     acceleration_;
        float       life_span_;
        float       mass_;
    };
}

#endif
