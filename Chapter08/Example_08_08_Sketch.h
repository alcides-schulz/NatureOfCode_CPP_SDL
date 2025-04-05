#ifndef EXAMPLE_08_08_SKETCH_H
#define EXAMPLE_08_08_SKETCH_H

#include "../Common/P5SDL.h"

namespace nature_of_code_chapter_08_example_08
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.8: Simple L-system Sentence Generation", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        void Generate(void);
    private:
        string      _current;
    };
}

#endif
