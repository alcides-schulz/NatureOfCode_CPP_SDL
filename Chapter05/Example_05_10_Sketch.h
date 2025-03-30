#ifndef EXAMPLE_05_10_SKETCH_H
#define EXAMPLE_05_10_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_10_Vehicle.h"

namespace nature_of_code_chapter_05_example_10
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.10: Combining Steering Behaviors (Seek and Separate)", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        vector <Vehicle *> _vehicles;
    };
}

#endif
