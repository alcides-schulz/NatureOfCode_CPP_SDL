#include "Example_09_04_Population.h"

namespace nature_of_code_chapter_09_example_04
{
    Population::Population(P5SDL *p5sdl, float mutation_rate, int size)
    {
        _p5sdl = p5sdl;
        _mutation_rate = mutation_rate;
        _generations = 0;
        for (int i = 0; i < size; i++)
            _flowers.push_back(new Flower(p5sdl, new DNA(), 40 + i * 80, 120));
    }

    void Population::Show(void)
    {
        for (auto flower : _flowers)
            flower->Show();
    }

    void Population::Rollover(int mouse_x, int mouse_y)
    {
        for (auto flower : _flowers)
            flower->Rollover(mouse_x, mouse_y);
    }

    Flower *Population::WeightedSelection(void)
    {
        int index = 0;
        float start = Utils::Random(1.0f);
        while (start > 0) {
            start -= _flowers[index]->GetFitness();
            index++;
        }
        index--;
        return _flowers[index];
    }

    void Population::Selection(void)
    {
        float total_fitness = 0;
        for (auto flower : _flowers)
            total_fitness += flower->GetFitness();
        for (auto flower : _flowers)
            flower->DivideFitness(total_fitness);
    }

    void Population::Reproduction(void)
    {
        vector<Flower *> next_flowers;
        for (int i = 0; i < _flowers.size(); i++) {
            auto parentA = WeightedSelection();
            auto parentB = WeightedSelection();
            auto child = parentA->GetDNA()->Crossover(parentB->GetDNA());
            child->Mutate(_mutation_rate);
            next_flowers.push_back(new Flower(_p5sdl, child, 40 + i * 80, 120));
        }
        for (auto flower : _flowers)
            delete flower;
        _flowers.assign(next_flowers.begin(), next_flowers.end());
        _generations++;
    }
}

// END
