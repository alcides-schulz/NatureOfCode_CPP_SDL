#ifndef EXAMPLE_08_06_SKETCH_H
#define EXAMPLE_08_06_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_08_example_06
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.6: A Recursive Tree", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Branch(int lenght);
    private:
        double _angle;
    };
}

#endif
