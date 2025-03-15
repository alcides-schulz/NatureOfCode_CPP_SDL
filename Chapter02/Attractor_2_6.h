#ifndef ATTRACTOR_2_6_H
#define ATTRACTOR_2_6_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"
#include "Mover_2_6.h"

class Attractor_2_6
{
public:
    Attractor_2_6(PVector position, int mass) : position_(position), mass_(mass) { };
    PVector Attract(Mover_2_6 *mover);
    void Show(SDL_Framework *framework);
    PVector GetPosition(void) { return position_; };
    void SetPosition(PVector position) { position_ = position; };
    int GetRadius(void) { return mass_; };

    static const int kGravity = 1;
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     mass_;
};


#endif

