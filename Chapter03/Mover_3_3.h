#ifndef MOVER_3_3_H
#define MOVER_3_3_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Mover_3_3
{
public:
    Mover_3_3(PVector position) : position_(position)
    {
        velocity_ = PVector(0, 0);
        acceleration_ = PVector(0, 0);
        top_speed_ = 2;
    };
    void Update(SDL_Framework *framework);
    void Show(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    float   top_speed_;
};

#endif

