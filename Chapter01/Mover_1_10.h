#ifndef MOVER_1_10_H
#define MOVER_1_10_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Mover_1_10 
{
public:
    Mover_1_10(PVector position, PVector velocity) : position_(position), velocity_(velocity)
    {
        acceleration_ = PVector(0, 0);
        top_speed_ = 2;
    };
    void Update(void);
    void Show(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
    PVector GetPosition(void) { return position_; };
    void SetAcceleration(PVector acceleration) { acceleration_ = acceleration; };
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    float   top_speed_;
};

#endif
