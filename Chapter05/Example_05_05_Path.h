#ifndef EXAMPLE_05_05_PATH_H
#define EXAMPLE_05_05_PATH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_05
{
    class Path
    {
    public:
        Path(P5SDL *p5sdl)
        {
            radius_ = 20;
            start_ = Vector(0, p5sdl->Height() / 3);
            end_ = Vector(p5sdl->Width(), (2 * p5sdl->Height()) / 3);
        }
        void Show(P5SDL *p5sdl);
    private:
        int     radius_;
        Vector start_;
        Vector end_;
    };
}

#endif

