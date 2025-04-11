#include "Example_09_01_DNA.h"

namespace nature_of_code_chapter_09_example_01
{
    DNA::DNA(int length)
    {
        _genes = "";
        _fitness = 0;
        for (int i = 0; i < length; i++)
            _genes += RandomCharacter();
    }

    void DNA::CalculateFitness(string target)
    {
        int score = 0;
        for (int i = 0; i < _genes.length(); i++) {
            if (_genes[i] == target[i])
                score++;
        }
        _fitness = (double)score / (double)target.length();
    }

    DNA *DNA::Crossover(DNA *partner)
    {
        auto child = new DNA((int)_genes.length());

        auto midpoint = floor(Utils::Random((int)_genes.length()));

        for (int i = 0; i < _genes.length(); i++) {
            if (i < midpoint)
                child->_genes[i] = _genes[i];
            else
                child->_genes[i] = partner->_genes[i];
        }

        return child;
    }

    void DNA::Mutate(double mutation_rate)
    {
        for (int i = 0; i < _genes.length(); i++) {
            if (Utils::Random(1.0f) < mutation_rate)
                _genes[i] = RandomCharacter();
        }
    }

    char DNA::RandomCharacter(void)
    {
        return (char)floor(Utils::Random(32, 127));
    }

}

// END
