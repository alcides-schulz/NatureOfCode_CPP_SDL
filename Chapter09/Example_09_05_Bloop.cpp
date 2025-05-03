#include "Example_09_05_Bloop.h"

namespace nature_of_code_chapter_09_example_05
{
    Bloop::Bloop(P5SDL *p5sdl, Vector position, DNA *dna)
    {
        _p5sdl = p5sdl;
        _position = position;
        _dna = dna;
        _health = 200;
        _xoff = Utils::Random(1000.0f);
        _yoff = Utils::Random(1000.0f);
        _max_speed = (float)Utils::Map(_dna->GetGenes()[0], 0, 1, 15, 0);
        _radius = (int)Utils::Map(_dna->GetGenes()[0], 0, 1, 0, 25);
    }

    Bloop::~Bloop(void)
    {
        delete _dna;
    }

    void Bloop::Run(void)
    {
        Update();
        Borders();
        Show();
    }

    void Bloop::Eat(Food *food)
    {
        auto& positions = food->GetPositions();
        for (int i = (int)positions.size() - 1; i >= 0; i--) {
            auto distance = Vector::Distance(_position, positions[i]);
            if (distance < _radius * 2) {
                _health += 100;
                positions.erase(positions.begin() + i);
            }
        }
    }

    Bloop *Bloop::Reproduce(void)
    {
        if (Utils::Random(1.0f) < 0.005f) {
            auto child_dna = _dna->Copy();
            child_dna->Mutate(0.01f);
            return new Bloop(_p5sdl, _position.Copy(), child_dna);
        }
        else {
            return nullptr;
        }
    }

    void Bloop::Update(void)
    {
        auto vx = (float)Utils::Map(_perlin.Noise(_xoff, 0), 0, 1, -_max_speed, _max_speed);
        auto vy = (float)Utils::Map(_perlin.Noise(_yoff, 0), 0, 1, -_max_speed, _max_speed);
        auto velocity = Vector(vx, vy);
        _xoff += 0.01f;
        _yoff += 0.01f;
        _position.Add(velocity);
        _health -= 0.2f;
    }

    void Bloop::Borders(void)
    {
        if (_position.x < -_radius)
            _position.x = (float)(_p5sdl->Width() + _radius);
        if (_position.y < _radius)
            _position.y = (float)(_p5sdl->Height() + _radius);
        if (_position.x > _p5sdl->Width() + _radius)
            _position.x = (float)(-_radius);
        if (_position.y > _p5sdl->Height() + _radius)
            _position.y = (float)(-_radius);
    }

    void Bloop::Show(void)
    {
        _p5sdl->Stroke(0, (Uint8)_health);
        _p5sdl->Fill(0, (Uint8)_health);
        _p5sdl->Circle(_position.x, _position.y, _radius * 2);
    }

    bool Bloop::IsDead(void)
    {
        return _health < 0;
    }
}

// END
