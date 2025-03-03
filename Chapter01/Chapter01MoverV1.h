#ifndef CHAPTER01MOVERV1_H
#define CHAPTER01MOVERV1_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Chapter01MoverV1 
{
public:
    Chapter01MoverV1(PVector location, PVector velocity) : location_(location), velocity_(velocity)
    {
        radius_ = 16; 
        acceleration_ = PVector(0, 0);
        top_speed_ = 2;
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
    int     radius_;
};

#endif
