#ifndef EXAMPLE_02_08_BODY_H
#define EXAMPLE_02_08_BODY_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_02_example_08
{
    class Body
    {
    public:
        Body(Vector position, int mass) : position_(position), mass_(mass)
        {
            radius_ = (int)(std::sqrtf((float)mass_) * 2.0f);
            acceleration_ = Vector(0.0f, 0.0f);
        };
        void ApplyForce(Vector force);
        void Update(void);
        void Show(SDL_Framework *framework);
        int GetMass(void) { return mass_; };
        Vector GetPosition(void) { return position_; };
        void SetVelocity(Vector velocity) { velocity_ = velocity; };
        void Attract(Body *body);
        static const int kGravity = 1;
    private:
        Vector position_;
        Vector velocity_;
        Vector acceleration_;
        int     radius_;
        int     mass_;
    };
}

#endif
