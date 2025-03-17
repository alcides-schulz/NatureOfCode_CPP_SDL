#ifndef MOVER_1_9_H
#define MOVER_1_9_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Mover_1_9 
{
public:
    Mover_1_9(PVector position, PVector velocity) : position_(position), velocity_(velocity)
    {
        top_speed_ = 2;
    };
    void Update(void);
    void Show(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    float   top_speed_;
};

#endif
