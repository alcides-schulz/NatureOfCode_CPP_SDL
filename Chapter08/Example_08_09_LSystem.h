#ifndef EXAMPLE_08_09_LSYSTEM_H
#define EXAMPLE_08_09_LSYSTEM_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_08_example_09
{
    class LSystem
    {
    public:
        LSystem(string axiom, map<char, string> rules);
        void Generate(void);
        string GetSentence(void) { return _sentence; };
    private:
        string _sentence;
        map<char, string> _ruleset;
    };
}

#endif
