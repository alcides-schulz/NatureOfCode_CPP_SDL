#ifndef EXAMPLE_09_02_ROCKET_H
#define EXAMPLE_09_02_ROCKET_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_09_02_DNA.h"

namespace nature_of_code_chapter_09_example_02
{
    extern Vector gTarget;

    class Rocket
    {
    public:
        Rocket(P5SDL *p5sdl, int x, int y, DNA *dna);
        void CalculateFitness(void);
        void Run(void);
        void ApplyForce(Vector force);
        void Update(void);
        void Show(void);
    private:
        P5SDL *_p5sdl;
        Vector _acceleration;
        Vector _velocity;
        Vector _position;
        int _r;
        double _fitness;
        DNA *_dna;
        int _gene_counter;
    };
}

#endif
