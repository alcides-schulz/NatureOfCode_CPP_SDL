#ifndef EXAMPLE_05_06_SKETCH_H
#define EXAMPLE_05_06_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_06_Path.h"
#include "Example_05_06_Vehicle.h"

namespace nature_of_code_chapter_05_example_06
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.6: Simple Path Following", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Path    *_path;
        Vehicle *_vehicle1;
        Vehicle *_vehicle2;
        bool    _debug;
    };
}

#endif
