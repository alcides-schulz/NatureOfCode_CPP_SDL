#ifndef EXAMPLE_09_05_BLOOP_H
#define EXAMPLE_09_05_BLOOP_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "../Common/PerlinNoise2D.h"

#include "Example_09_05_DNA.h"
#include "Example_09_05_Food.h"

namespace nature_of_code_chapter_09_example_05
{
    class Bloop
    {
    public:
        Bloop(P5SDL *p5sdl, Vector position, DNA *dna);
        ~Bloop(void);
        void Run(void);
        void Update(void);
        void Borders(void);
        void Show(void);
        void Eat(Food *food);
        Bloop *Reproduce(void);
        bool IsDead(void);
        Vector GetPosition(void) { return _position; };
    private:
        P5SDL   *_p5sdl;
        Vector  _position;
        DNA     *_dna;
        float   _xoff;
        float   _yoff;
        float   _health;
        float   _max_speed;
        int     _radius;
        PerlinNoise2D _perlin;
    };
}

#endif
