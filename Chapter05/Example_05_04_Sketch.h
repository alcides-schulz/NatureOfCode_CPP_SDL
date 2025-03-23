#ifndef EXAMPLE_05_04_SKETCH_H
#define EXAMPLE_05_04_SKETCH_H

#include "../Common/SDL_Framework.h"
#include "Example_05_04_Vehicle.h"
#include "Example_05_04_FlowField.h"

namespace nature_of_code_chapter_05_example_04
{
    class Sketch : public SDL_Framework
    {
    public:
        Sketch() : SDL_Framework("Example 5.4: Flow Field Following", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        vector<Vehicle *> vehicles_;
        FlowField   *flowfield_;
        bool        debug_;
    };
}

#endif
