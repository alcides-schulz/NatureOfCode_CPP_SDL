#ifndef ATTRACTOR_3_2_H
#define ATTRACTOR_3_2_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_3_2.h"

class Attractor_3_2
{
public:
    Attractor_3_2(PVector position, int mass) : position_(position), mass_(mass)
    { 
        radius_ = mass;
    };
    PVector Attract(Mover_3_2 *mover);
    void Display(SDL_Framework *framework);
    PVector GetPosition(void) { return position_; };
    void SetPosition(PVector position) { position_ = position; };
    int GetRadius(void) { return radius_; };
    static const int kGravity = 1;
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     radius_;
    int     mass_;
};


#endif

