#include "Example_05_12_Boid.h"

namespace nature_of_code_chapter_05_example_12
{
    Boid::Boid(P5SDL *p5sdl, int x, int y)
    {
        _p5sdl = p5sdl;
        _position = Vector(x, y);
        _acceleration = Vector(0, 0);
        _velocity = Vector(Utils::Random(-1.0f, 1.0f), Utils::Random(-1.0f, 1.0f));
        _r = 3;
        _max_speed = 3.0f;
        _max_force = 0.05f;
    };

    void Boid::Run()
    {
        auto col = (int)floor(_position.x / gResolution);
        auto row = (int)floor(_position.y / gResolution);
        vector<Boid *> neighbors;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                auto new_col = col + i;
                auto new_row = row + j;
                if (new_col >= 0 && new_col < gCols && new_row >= 0 && new_row < gRows) {
                    neighbors.insert(neighbors.end(), gGrid[new_col][new_row].begin(), gGrid[new_col][new_row].end());
                }
            }
        }

        Flock(neighbors);
        Update();
        Borders();
        Show();
    }

    void Boid::ApplyForce(Vector force)
    {
        _acceleration.Add(force);
    }

    void Boid::Flock(vector<Boid *> boids)
    {
        auto sep = Separate(boids);
        auto ali = Align(boids);
        auto coh = Cohere(boids);
        sep.Mult(1.5f);
        ali.Mult(1.0f);
        coh.Mult(1.0f);
        ApplyForce(sep);
        ApplyForce(ali);
        ApplyForce(coh);
    }

    void Boid::Update(void)
    {
        _velocity.Add(_acceleration);
        _velocity.Limit(_max_speed);
        _position.Add(_velocity);
        _acceleration.Mult(0);
    }

    Vector Boid::Seek(Vector target)
    {
        auto desired = Vector::Sub(target, _position);
        desired.Normalize();
        desired.Mult(_max_speed);
        auto steer = Vector::Sub(desired, _velocity);
        steer.Limit(_max_force);
        return steer;
    }

    void Boid::Show()
    {
        auto angle = _velocity.Heading();
        _p5sdl->Fill(127);
        _p5sdl->Stroke(0);
        _p5sdl->StrokeWeight(1);
        _p5sdl->Translate(_position.x, _position.y);
        _p5sdl->Rotate(angle);
        SDL_Point vertices[] = {
            {_r * 2, 0},
            {-_r * 2, -_r},
            {-_r * 2, _r},
            {_r * 2, 0},
        };
        _p5sdl->Lines(vertices, 4);
        _p5sdl->ResetMatrix();
    }

    void Boid::Borders()
    {
        if (_position.x < -_r) _position.x = (float)(_p5sdl->Width() + _r);
        if (_position.y < -_r) _position.y = (float)(_p5sdl->Height() + _r);
        if (_position.x > _p5sdl->Width() + _r) _position.x = (float)-_r;
        if (_position.y > _p5sdl->Height() + _r) _position.y = (float)-_r;
    }

    Vector Boid::Separate(vector<Boid *> boids)
    {
        auto desired_separation = 25;
        auto steer = Vector(0, 0);
        auto count = 0;
        for (auto other : boids)
        {
            auto distance = Vector::Distance(_position, other->_position);
            if (distance > 0 && distance < desired_separation) {
                auto diff = Vector::Sub(_position, other->_position);
                diff.Normalize();
                diff.Div(distance);
                steer.Add(diff);
                count++;
            }
        }
        if (count > 0) {
            steer.Div((float)count);
        }
        if (steer.Mag() > 0) {
            steer.Normalize();
            steer.Mult(_max_speed);
            steer.Sub(_velocity);
            steer.Limit(_max_force);
        }
        return steer;
    }

    Vector Boid::Align(vector<Boid *> boids)
    {
        auto neighbor_distance = 50;
        auto sum = Vector(0, 0);
        auto count = 0;
        for (auto other : boids) {
            auto distance = Vector::Distance(_position, other->_position);
            if (distance > 0 && distance < neighbor_distance) {
                sum.Add(other->_velocity);
                count++;
            }
        }
        if (count > 0) {
            sum.Div((float)count);
            sum.Normalize();
            sum.Mult(_max_speed);
            auto steer = Vector::Sub(sum, _velocity);
            steer.Limit(_max_force);
            return steer;
        }
        else {
            return Vector(0, 0);
        }
    }

    Vector Boid::Cohere(vector<Boid *> boids)
    {
        auto neighbor_distance = 50;
        auto sum = Vector(0, 0);
        auto count = 0;
        for (auto other : boids) {
            auto distance = Vector::Distance(_position, other->_position);
            if (distance > 0 && distance < neighbor_distance) {
                sum.Add(other->_position);
                count++;
            }
        }
        if (count > 0) {
            sum.Div((float)count);
            return Seek(sum);
        }
        else {
            return Vector(0, 0);
        }
    }
    
}
 
// END
