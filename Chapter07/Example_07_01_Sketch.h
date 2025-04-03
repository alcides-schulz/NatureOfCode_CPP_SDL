#ifndef EXAMPLE_07_01_SKETCH_H
#define EXAMPLE_07_01_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_07_example_01
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 7.1: Wolfram Elementary Cellular Automata", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        int Sketch::Rules(int a, int b, int c);
    private:
        vector<int> _cells;
        int         _generation;
        int         _w;
        vector<int> _rule_set;
    };
}

#endif
