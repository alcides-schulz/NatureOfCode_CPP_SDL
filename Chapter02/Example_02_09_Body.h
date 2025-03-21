#ifndef EXAMPLE_02_09_BODY_H
#define EXAMPLE_02_09_BODY_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_02_example_09
{
    class Body
    {
    public:
        Body(PVector position, int mass) : position_(position), mass_(mass)
        {
            acceleration_ = PVector(0.0f, 0.0f);
        };
        void ApplyForce(PVector force);
        void Update(void);
        void Show(SDL_Framework *framework);
        int GetMass(void) { return mass_; };
        PVector GetPosition(void) { return position_; };
        void SetVelocity(PVector velocity) { velocity_ = velocity; };
        void Attract(Body *body);
        static const int kGravity = 1;
    private:
        PVector position_;
        PVector velocity_;
        PVector acceleration_;
        int     mass_;
    };
}

#endif
