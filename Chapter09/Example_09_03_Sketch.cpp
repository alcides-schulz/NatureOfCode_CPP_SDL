#include "Example_09_03_Sketch.h"

namespace nature_of_code_chapter_09_example_03
{
    Obstacle *gTarget;

    bool Sketch::Setup(void)
    {
        gTarget = new Obstacle(this, Width() / 2 -12, 24, 24, 24);
        _life_span = 250;
        _life_counter = 0;
        _record_time = _life_span;
        _population = new Population(this, 0.01f, 150);
        _obstacles.push_back(new Obstacle(this, Width() / 2 - 75, Height() / 2, 150, 10));
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        gTarget->Show();

        if (_life_counter < _life_span) {
            _population->Live(_obstacles);
            if (_population->TargetReached() && _life_counter < _record_time) {
                _record_time = _life_counter;
            }
            else {
                _life_counter++;
            }
        }
        else {
            _life_counter = 0;
            _population->CalculateFitness();
            _population->Selection();
            _population->Reproduction();
        }

        for (auto obstacle : _obstacles)
            obstacle->Show();

        Fill(0);
        Text(" Generation #: " + to_string(_population->GetGenerations()), 10, 20);
        Text("  Cycles Left: " + to_string(_life_span - _life_counter), 10, 40);
        Text("Record cycles: " + to_string(_record_time), 10, 60);

        if (IsMouseButtonClicked(kMouseLeftButton)) {
            gTarget->SetPosition(Vector(MousePosition().x, MousePosition().y));
            _record_time = _life_span;
        }

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _population;
        delete gTarget;
    }
}

// END
