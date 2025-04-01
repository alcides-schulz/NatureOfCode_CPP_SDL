#ifndef EXAMPLE_05_12_BOID_H
#define EXAMPLE_05_12_BOID_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_05_example_12
{
    class Boid
    {
    public:
        Boid(P5SDL *p5sdl, int x, int y);
        void Run(void);
        void Flock(vector<Boid *> boids);
        Vector Separate(vector<Boid *> boids);
        Vector Align(vector<Boid *> boids);
        Vector Cohere(vector<Boid *> boids);
        void ApplyForce(Vector force);
        Vector Seek(Vector target);
        void Update(void);
        void Borders(void);
        void Show(void);
        Vector GetPosition(void) { return _position; };
    private:
        P5SDL   *_p5sdl;
        Vector  _position;
        Vector  _velocity;
        Vector  _acceleration;
        int     _r;
        float   _max_speed;
        float   _max_force;
    };

    extern vector<vector<vector<Boid *>>> gGrid;
    extern int gRows;
    extern int gCols;
    extern int gResolution;
}

#endif
