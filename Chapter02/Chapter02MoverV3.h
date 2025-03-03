#ifndef CHAPTER02MOVERV3_H
#define CHAPTER02MOVERV3_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

class Chapter02MoverV3
{
public:
    Chapter02MoverV3::Chapter02MoverV3(PVector position, int mass) : position_(position), mass_(mass) {
        velocity_ = PVector(0, 0);
        radius_ = 10 * mass;
        acceleration_ = PVector(0.0f, 0.0f);
    };
    void ApplyForce(PVector force);
    void Update(void);
    void Display(SDL_Framework *framework);
    void CheckEdges(SDL_Framework *framework);
    bool ContactEdge(SDL_Framework *framework);
    void BounceEdges(SDL_Framework *framework);
    int GetMass(void) { return mass_; };
    PVector GetVelocity(void) { return velocity_; };
    PVector GetPosition(void) { return position_; };
private:
    PVector position_;
    PVector velocity_;
    PVector acceleration_;
    int     radius_;
    int     mass_;
};

#endif

