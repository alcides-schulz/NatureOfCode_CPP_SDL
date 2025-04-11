#include "Example_09_01_Sketch.h"

namespace nature_of_code_chapter_09_example_01
{
    bool Sketch::Setup(void)
    {
        for (int i = 0; i < kPopulationSize; i++) {
            _population.push_back(new DNA((int)kTarget.length()));
        }
        TextSize(12);
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        for (auto phrase : _population)
            phrase->CalculateFitness(kTarget);
        
        vector<DNA *> mating_pool;
        for (auto phrase : _population) {
            auto n = floor(phrase->GetFitness() * 100);
            for (int j = 0; j < n; j++) {
                mating_pool.push_back(phrase);
            }
        }
        
        auto old_dna_list = _population;
        map<double, DNA *> sorted_dna;
        for (int i = 0; i < _population.size(); i++) {
            auto partnerA = mating_pool[Utils::Random((int)mating_pool.size() - 1)];
            auto partnerB = mating_pool[Utils::Random((int)mating_pool.size() - 1)];

            auto child = partnerA->Crossover(partnerB);

            child->Mutate(kMutationRate);

            _population[i] = child;

            child->CalculateFitness(kTarget);
            sorted_dna[-(child->GetFitness() * 1000000 + i)] = child;
        }
        for (auto old_dna : old_dna_list)
            delete old_dna;
        
        // show top dna ordered by fitness
        string line = "";
        int row = 0;
        int count = 0;
        int max_display = Height() / 20 * 4;
        for (auto& pair : sorted_dna)
        {
            line += pair.second->GetPhase() + "    ";
            count++;
            if (count % 4 == 0) {
                Text(line, 20, row * 20);
                line = "";
                row++;
            }
            if (count >= max_display)
                break;
        }
        
        return true;
    }

    void Sketch::Cleanup(void)
    {
        for (int i = 0; i < _population.size(); i++) {
            delete _population[i];
        }
    }
}

// END
