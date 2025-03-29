#ifndef EXAMPLE_05_06_PATH_H
#define EXAMPLE_05_06_PATH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_06
{
    class Path
    {
    public:
        Path(P5SDL *p5sdl);
        void Show(P5SDL *p5sdl);
        Vector GetStart(void) { return start_; };
        Vector GetEnd(void) { return end_; };
        int GetRadius(void) { return radius_; };
    private:
        int     radius_;
        Vector start_;
        Vector end_;
    };
}

#endif

