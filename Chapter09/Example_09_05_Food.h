#ifndef EXAMPLE_09_05_FOOD_H
#define EXAMPLE_09_05_FOOD_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"

namespace nature_of_code_chapter_09_example_05
{
    class Food
    {
    public:
        Food(P5SDL *p5sdl, int num);
        void Add(Vector position);
        void Run(void);
        vector<Vector>& GetPositions(void) { return _food_positions; };
    private:
        P5SDL         *_p5sdl;
        vector<Vector> _food_positions;
    };
}

#endif
