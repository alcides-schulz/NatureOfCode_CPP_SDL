#include "Example_09_03_Population.h"

namespace nature_of_code_chapter_09_example_03
{
    Population::Population(P5SDL *p5sdl, float mutation, int length)
    {
        _p5sdl = p5sdl;
        _mutation_rate = mutation;
        _generations = 0;
        for (int i = 0; i < length; i++) {
            _population.push_back(new Rocket(p5sdl, 320, 220, new DNA()));
        }
    }

    Population::~Population(void)
    {
        for (auto rocket : _population)
            delete rocket;
        _population.clear();
    }

    void Population::Live(vector<Obstacle *> obstacles)
    {
        for (auto rocket : _population) {
            rocket->CheckTarget();
            rocket->Run(obstacles);
        }
    }

    bool Population::TargetReached(void)
    {
        for (auto rocket : _population) {
            if (rocket->HitTarget())
                return true;
        }
        return false;
    }

    void Population::CalculateFitness(void)
    {
        for (auto rocket : _population)
            rocket->CalculateFitness();
    }

    void Population::Selection(void)
    {
        float total_fitness = 0;
        for (auto rocket : _population)
            total_fitness += rocket->GetFitness();
        for (auto rocket : _population)
            rocket->SetFitness(rocket->GetFitness() / total_fitness);
    }

    void Population::Reproduction(void)
    {
        vector<Rocket *> next_population;
        for (int i = 0; i < _population.size(); i++)
        {
            auto parentA = WeightedSelection();
            auto parentB = WeightedSelection();
            auto child = parentA->Crossover(parentB);
            child->Mutate(_mutation_rate);
            next_population.push_back(new Rocket(_p5sdl, 320, 220, child));
        }
        for (auto rocket : _population)
            delete rocket;
        _population.assign(next_population.begin(), next_population.end());
        _generations++;
    }

    DNA *Population::WeightedSelection(void)
    {
        auto index = 0;
        auto start = Utils::Random(1.0f);
        while (start > 0 && index < _population.size()) {
            start -= _population[index]->GetFitness();
            index++;
        }
        index--;
        return _population[max(0, index)]->GetDNA();
    }
}

// END
