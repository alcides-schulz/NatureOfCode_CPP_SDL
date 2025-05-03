#include "Example_09_05_DNA.h"

namespace nature_of_code_chapter_09_example_05
{
    DNA::DNA(void)
    {
        for (int i = 0; i < 1; i++)
            _genes.push_back(Utils::Random(0, 1));
    }

    DNA *DNA::Copy(void)
    {
        auto new_dna = new DNA();
        new_dna->_genes.assign(_genes.begin(), _genes.end());
        return new_dna;
    }

    void DNA::Mutate(float mutation_rate)
    {
        for (int i = 0; i < _genes.size(); i++)
            if (Utils::Random(1.0f) < mutation_rate)
                _genes[i] = Utils::Random(1.0f);
    }
}

// END
