#include "Example_09_04_DNA.h"

namespace nature_of_code_chapter_09_example_04
{
    DNA::DNA() 
    {
        for (int i = 0; i < 14; i++)
            _genes.push_back(Utils::Random(0, 1));
    }

    DNA *DNA::Crossover(DNA *partner)
    {
        auto child = new DNA();
        auto midpoint = Utils::Random((int)_genes.size());
        for (int i = 0; i < _genes.size(); i++) {
            if (i < midpoint)
                child->_genes[i] = _genes[i];
            else
                child->_genes[i] = partner->_genes[i];
        }
        return child;
    }

    void DNA::Mutate(float mutation_rate)
    {
        for (int i = 0; i < _genes.size(); i++) {
            if (Utils::Random(1.0f) < mutation_rate)
                _genes[i] = Utils::Random(0, 1);
        }
    }
}

// END
