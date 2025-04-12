#include "Example_09_03_Rocket.h"

namespace nature_of_code_chapter_09_example_03
{
    Rocket::Rocket(P5SDL *p5sdl, int x, int y, DNA *dna)
    {
        _p5sdl = p5sdl;
        _acceleration = Vector(0, 0);
        _velocity = Vector(0, 0);
        _position = Vector(x, y);
        _r = 4;
        _dna = dna;
        _gene_counter = 0;
        _finish_counter = 0;
        _record_distance = FLT_MAX;
        _fitness = 0;
        _gene_counter = 0;
        _hit_obstacle = false;
        _hit_target = false;
    }

    Rocket::~Rocket(void)
    {
        delete _dna;
    }

    void Rocket::CalculateFitness(void)
    {
        _fitness = 1.0f / (_finish_counter * _record_distance);
        _fitness = powf(_fitness, 4);
        if (_hit_obstacle)
            _fitness *= 0.1f;
        if (_hit_target)
            _fitness *= 2.0f;
    }

    void Rocket::Run(vector<Obstacle *> obstacles)
    {
        if (!_hit_obstacle && !_hit_target) {
            ApplyForce(_dna->GetGene(_gene_counter));
            _gene_counter = (_gene_counter + 1) % _dna->Length();
            Update();
            CheckObstacles(obstacles);
        }
        Show();
    }

    void Rocket::CheckObstacles(vector<Obstacle *> obstacles)
    {
        for (auto obstacle : obstacles)
            if (obstacle->Contains(_position))
                _hit_obstacle = true;
    }

    void Rocket::CheckTarget(void)
    {
        auto distance = Vector::Distance(_position, gTarget->GetPosition());
        if (distance < _record_distance)
            _record_distance = distance;
        if (gTarget->Contains(_position))
            _hit_target = true;
        if (!_hit_target)
            _finish_counter++;
    }

    void Rocket::ApplyForce(Vector force)
    {
        _acceleration.Add(force);
    }

    void Rocket::Update(void)
    {
        _velocity.Add(_acceleration);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }

    void Rocket::Show(void)
    {
        auto theta = _velocity.Heading() + M_PI / 2;
        _p5sdl->Fill(200, 100);
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(1);
        _p5sdl->Push();
        _p5sdl->Translate(_position.x, _position.y);
        _p5sdl->Rotate(theta);
        auto r = _r;
        _p5sdl->RectMode(kRectCenter);
        _p5sdl->Fill(0);
        _p5sdl->Rect(-r / 2, r * 2, 2, 2);
        _p5sdl->Rect(r / 2, r * 2, 2, 2);
        SDL_Point rocket[] = {
            {0, -r * 2},
            {-r, r * 2},
            {r, r * 2},
            {0, -r * 2},
        };
        _p5sdl->Fill(200);
        _p5sdl->Lines(rocket, 4);
        _p5sdl->Pop();
    }

}

// END
