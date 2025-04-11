#include "Example_09_02_DNA.h"

namespace nature_of_code_chapter_09_example_02
{
    DNA::DNA()
    {
        _max_force = 0.1f;
        for (int i = 0; i < kLifeSpan; i++) {
            auto angle = Utils::Random((float)M_PI * 2.0f);
            _genes[i] = Vector::FromAngle(angle);
            _genes[i].Mult((float)Utils::Random(0, _max_force));
        }
    }

    DNA *DNA::Crossover(DNA *partner)
    {
        auto child = new DNA();
        auto mid_point = Utils::Random((int)_genes.size());
        for (int i = 0; i < _genes.size(); i++) {
            if (i < mid_point)
                child->_genes[i] = _genes[i];
            else
                child->_genes[i] = partner->_genes[i];
        }
    }

    void DNA::Mutate(float m)
    {
        for (int i = 0; i < _genes.size(); i++) {
            if (Utils::Random(1.0f) < m) {
                auto angle = Utils::Random((float)M_PI * 2.0f);
                _genes[i] = Vector::FromAngle(angle);
                _genes[i].Mult((float)Utils::Random(0, _max_force));
            }
        }
    }
}

// END
