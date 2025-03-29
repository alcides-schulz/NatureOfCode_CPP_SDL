#ifndef EXAMPLE_04_04_SKETCH_H
#define EXAMPLE_04_04_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_04_04_Emitter.h"

namespace nature_of_code_chapter_04_example_04
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.4: A System of Systems", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
    private:
        vector<Emitter     *>   emitters_;
    };
}

#endif
