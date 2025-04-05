#include "Example_08_09_LSystem.h"

namespace nature_of_code_chapter_08_example_09
{
    LSystem::LSystem(string axiom, map<char, string> rules)
    {
        _sentence = axiom;
        _ruleset = rules;
    }

    void LSystem::Generate(void)
    {
        string next_gen = "";
        for (int i = 0; i < _sentence.length(); i++) {
            auto c = _sentence[i];
            if (_ruleset.find(c) != _ruleset.end())
                next_gen += _ruleset[c];
            else
                next_gen += c;
        }
        _sentence = next_gen;
    }
}

// END
