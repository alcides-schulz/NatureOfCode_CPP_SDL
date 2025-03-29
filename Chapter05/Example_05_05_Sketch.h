#ifndef EXAMPLE_05_05_SKETCH_H
#define EXAMPLE_05_05_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_05_05_Path.h"

namespace nature_of_code_chapter_05_example_05
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 5.5: Creating a Path Object", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Path    *_path;
    };
}

#endif
