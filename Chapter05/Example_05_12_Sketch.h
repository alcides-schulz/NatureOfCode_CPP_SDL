#ifndef EXAMPLE_05_12_SKETCH_H
#define EXAMPLE_05_12_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_12_Flock.h"

namespace nature_of_code_chapter_05_example_12
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.12: Bin-lattice Spatial Subdivision", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Flock   *_flock;
    };
}

#endif
