#ifndef EXAMPLE_05_06_SKETCH_H
#define EXAMPLE_05_06_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_05_06_Path.h"
#include "Example_05_06_Vehicle.h"

namespace nature_of_code_chapter_05_example_06
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 5.6: Simple Path Following", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Path    *path_;
        Vehicle *vehicle1_;
        Vehicle *vehicle2_;
        bool    debug_;
    };
}

#endif
