#include "Example_09_04_Sketch.h"

namespace nature_of_code_chapter_09_example_04
{
    bool Sketch::Setup(void)
    {
        int population_size = 8;
        float mutation_rate = 0.05f;
        _population = new Population(this, mutation_rate, population_size);
        TextSize(12);
        _evolve_button = new Button(this, "Evolve new Generation", 10, 10, 300, 30);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        _evolve_button->Show();
        _population->Show();
        _population->Rollover(MousePosition().x, MousePosition().y);
        Text("Generation " + to_string(_population->GetGeneration()), 12, Height() - 12);
        if (_evolve_button->Clicked())
            NextGeneration();
        return true;
    }
    
    void Sketch::NextGeneration(void)
    {
        _population->Selection();
        _population->Reproduction();
    }

    void Sketch::Cleanup(void)
    {
        delete _evolve_button;
        delete _population;
    }
}

// END
