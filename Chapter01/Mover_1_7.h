#ifndef MOVER_1_7_H
#define MOVER_1_7_H

#include "../Common/PVector.h"
#include "../Common/SDL_Framework.h"

class Mover_1_7 
{
public:
    Mover_1_7(PVector location, PVector velocity) : location_(location), velocity_(velocity) { };
    void Update(void);
    void Show(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
private:
    PVector location_;
    PVector velocity_;
};

#endif
