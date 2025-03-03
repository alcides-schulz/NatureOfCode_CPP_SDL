#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Chapter02MoverV1.h"

class Attractor
{
public:
    Attractor(PVector position, int mass) : position_(position), mass_(mass) 
    { 
        radius_ = mass * 4;
    };
    PVector Attract(Chapter02MoverV1 *mover);
    void Display(SDL_Framework *framework);
    PVector GetPosition(void) { return position_; };
    void SetPosition(PVector position) { position_ = position; };
    int GetRadius(void) { return radius_; };
    static const int kGravity = 10;
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     radius_;
    int     mass_;
};


#endif

