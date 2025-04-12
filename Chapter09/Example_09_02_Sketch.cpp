#include "Example_09_02_Sketch.h"

namespace nature_of_code_chapter_09_example_02
{
    Vector gTarget;

    bool Sketch::Setup(void)
    {
        gTarget = Vector(Width() / 2, 24);

        _life_span = 250;
        _life_counter = 0;
        auto mutation_rate = 0.01f;
        _population = new Population(this, mutation_rate, 50);

        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        Fill(127);
        Stroke(0);
        StrokeWeight(2);
        Circle(gTarget.x, gTarget.y, 24);

        if (_life_counter < _life_span) {
            _population->Live();
            _life_counter++;
        }
        else {
            _life_counter = 0;
            _population->Fitness();
            _population->Selection();
            _population->Reproduction();
        }

        Text("Generation #: " + to_string(_population->GetGenerations()), 10, 20);
        Text(" Cycles Left: " + to_string(_life_span - _life_counter), 10, 40);

        if (IsMouseButtonClicked(kMouseLeftButton)) {
            gTarget = Vector(MousePosition().x, MousePosition().y);
        }

        return true;
    }

    void Sketch::Cleanup(void)
    {
        delete _population;
    }
}

// END
