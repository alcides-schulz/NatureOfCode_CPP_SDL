#ifndef MOVER_1_8_H
#define MOVER_1_8_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Mover_1_8 
{
public:
    Mover_1_8(PVector location, PVector velocity) : location_(location), velocity_(velocity)
    {
        acceleration_ = PVector(0, 0);
        top_speed_ = 10;
    };
    void Update(void);
    void Display(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
    PVector GetLocation(void) { return location_; };
    void SetAcceleration(PVector acceleration) { acceleration_ = acceleration; };
private:
    PVector location_;
    PVector velocity_;
    PVector acceleration_;
    float   top_speed_;
};

#endif
