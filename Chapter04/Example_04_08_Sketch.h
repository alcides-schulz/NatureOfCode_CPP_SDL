#ifndef EXAMPLE_04_08_SKETCH_H
#define EXAMPLE_04_08_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_04_08_Emitter.h"

namespace nature_of_code_chapter_04_example_08
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 4.8: Image Texture System (smoke)", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Emitter     *emitter_;
        SDL_Texture* texture_;
    };
}

#endif
