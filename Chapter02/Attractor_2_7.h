#ifndef ATTRACTOR_2_7_H
#define ATTRACTOR_2_7_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_2_7.h"

class Attractor_2_7
{
public:
    Attractor_2_7(PVector position, int mass) : position_(position), mass_(mass)
    { 
        radius_ = mass_;
    };
    PVector Attract(Mover_2_7 *mover);
    void Show(SDL_Framework *framework);
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

