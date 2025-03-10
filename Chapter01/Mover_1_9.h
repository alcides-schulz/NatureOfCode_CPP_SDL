#ifndef MOVER_1_9_H
#define MOVER_1_9_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Mover_1_9 
{
public:
    Mover_1_9(PVector location, PVector velocity) : location_(location), velocity_(velocity)
    {
        top_speed_ = 5;
    };
    void Update(void);
    void Display(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
private:
    PVector location_;
    PVector velocity_;
    PVector acceleration_;
    float   top_speed_;
};

#endif
