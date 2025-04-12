#ifndef EXAMPLE_09_03_SKETCH_H
#define EXAMPLE_09_03_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "Example_09_03_Population.h"
#include "Example_09_03_Obstacle.h"

namespace nature_of_code_chapter_09_example_03
{
    extern Obstacle *gTarget;
    
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 9.3: Smarter Rockets", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
    private:
        Population *_population;
        int _life_span;
        int _life_counter;
        vector<Obstacle *> _obstacles;
        int _record_time;
    };
}

#endif
