#ifndef MOVER_2_2_H
#define MOVER_2_2_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Mover_2_2
{
public:
    Mover_2_2(PVector position, int mass) : position_(position), mass_(mass) { };
    void ApplyForce(PVector force);
    void Update(void);
    void Display(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
private:
    PVector position_;
    PVector velocity_ = PVector(0, 0);
    PVector acceleration_ = PVector(0, 0);
    int     mass_;
};

#endif

