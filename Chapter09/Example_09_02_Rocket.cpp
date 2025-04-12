#include "Example_09_02_Rocket.h"

namespace nature_of_code_chapter_09_example_02
{
    Rocket::Rocket(P5SDL *p5sdl, int x, int y, DNA *dna)
    {
        _p5sdl = p5sdl;
        _acceleration = Vector(0, 0);
        _velocity = Vector(0, 0);
        _position = Vector(x, y);
        _r = 4;
        _fitness = 0;
        _dna = dna;
        _gene_counter = 0;
    }

    Rocket::~Rocket(void)
    {
        delete _dna;
    }

    void Rocket::CalculateFitness(void)
    {
        auto distance = Vector::Distance(_position, gTarget);
        _fitness = 1 / (distance * distance);
    }

    void Rocket::Run(void)
    {
        ApplyForce(_dna->GetGene(_gene_counter));
        _gene_counter = _gene_counter + 1;
        Update();
        Show();
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
        auto angle = _velocity.Heading() + M_PI / 2;
        auto r = _r;
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(1);

        _p5sdl->Push();
        _p5sdl->Translate(_position.x, _position.y);
        _p5sdl->Rotate(angle);

        _p5sdl->RectMode(kRectCenter);
        _p5sdl->Fill(0);
        _p5sdl->Rect(-r / 2, r * 2, 2, 2);
        _p5sdl->Rect(r / 2, r * 2, 2, 2);

        _p5sdl->Fill(200);
        SDL_Point rocket[] = {
            {0, -r * 2},
            {-r, r * 2},
            {r, r * 2},
            {0, -r * 2},
        };
        _p5sdl->Lines(rocket, 4);
        _p5sdl->Pop();
    }

}

// END
