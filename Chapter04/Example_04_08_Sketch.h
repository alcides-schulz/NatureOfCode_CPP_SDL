#ifndef EXAMPLE_04_08_SKETCH_H
#define EXAMPLE_04_08_SKETCH_H

#include "../Common/P5SDL.h"
#include "Example_04_08_Emitter.h"

namespace nature_of_code_chapter_04_example_08
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 4.8: Image Texture System (smoke)", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Emitter     *emitter_;
        SDL_Texture* texture_;
    };
}

#endif
