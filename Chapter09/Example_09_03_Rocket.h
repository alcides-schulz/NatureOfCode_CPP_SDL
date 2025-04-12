#ifndef EXAMPLE_09_03_ROCKET_H
#define EXAMPLE_09_03_ROCKET_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_09_03_DNA.h"
#include "Example_09_03_Obstacle.h"

namespace nature_of_code_chapter_09_example_03
{
    extern Obstacle *gTarget;

    class Rocket
    {
    public:
        Rocket(P5SDL *p5sdl, int x, int y, DNA *dna);
        ~Rocket(void);
        void CalculateFitness(void);
        void Run(vector<Obstacle *> obstacles);
        void CheckObstacles(vector<Obstacle *> obstacles);
        void CheckTarget(void);
        void ApplyForce(Vector force);
        void Update(void);
        void Show(void);
        float GetFitness(void) { return _fitness; };
        void SetFitness(float fitness) { _fitness = fitness; };
        DNA *GetDNA(void) { return _dna; };
        bool HitTarget(void) { return _hit_target; };
    private:
        P5SDL *_p5sdl;
        Vector _acceleration;
        Vector _velocity;
        Vector _position;
        int _r;
        float _fitness;
        DNA *_dna;
        int _gene_counter;
        int _finish_counter;
        float _record_distance;
        bool _hit_obstacle;
        bool _hit_target;
    };
}

#endif
