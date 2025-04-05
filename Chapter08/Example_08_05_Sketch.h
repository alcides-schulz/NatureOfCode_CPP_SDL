#ifndef EXAMPLE_08_05_SKETCH_H
#define EXAMPLE_08_05_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_08_05_KochLine.h"

namespace nature_of_code_chapter_08_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 8.5: The KochLine Curve", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Generate(void);
        void Cleanup(void) override;
    private:
        vector<KochLine *>  _segments;
    };
}

#endif
