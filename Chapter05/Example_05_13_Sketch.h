#ifndef EXAMPLE_05_13_SKETCH_H
#define EXAMPLE_05_13_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_13_Quadtree.h"

namespace nature_of_code_chapter_05_example_13
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.13: Quadtree", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        QuadTree    *_quadtree;
    };
}

#endif
