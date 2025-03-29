#ifndef EXAMPLE_05_08_SKETCH_H
#define EXAMPLE_05_08_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_05_08_Path.h"
#include "Example_05_08_Vehicle.h"

namespace nature_of_code_chapter_05_example_08
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 5.8: Path Following", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
        void NewPath(void);
    private:
        Path    *path_;
        Vehicle *car1_;
        Vehicle *car2_;
        bool    debug_;
    };
}

#endif
