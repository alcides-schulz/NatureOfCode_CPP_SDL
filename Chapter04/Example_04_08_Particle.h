#ifndef EXAMPLE_04_08_PARTICLE_H
#define EXAMPLE_04_08_PARTICLE_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_04_example_08
{
    class Particle
    {
    public:
        Particle(int x, int y, SDL_Texture *texture)
        {
            position_ = PVector(x, y);
            texture_ = texture;
            auto vx = Utils::Random(0.0f, 0.3f);
            auto vy = Utils::Random(-1.0f, 0.3f);
            velocity_ = PVector(vx, vy);
            acceleration_ = PVector(0, 0);
            life_span_ = 100.0f;

            //this.position = createVector(x, y);
            //let vx = randomGaussian(0, 0.3);
            //let vy = randomGaussian(-1, 0.3);
            //this.velocity = createVector(vx, vy);
            //this.acceleration = createVector(0, 0);
            //this.lifespan = 100.0;

        };
        void Update(void);
        virtual void Show(SDL_Framework *framework);
        void ApplyForce(PVector force);
        bool IsDead(void) { return life_span_ < 0; };
        void Run(SDL_Framework *framework);
    protected:
        PVector     position_;
        SDL_Texture *texture_;
        PVector     velocity_;
        PVector     acceleration_;
        float       life_span_;
    };
}

#endif
