#ifndef EXAMPLE_05_05_PATH_H
#define EXAMPLE_05_05_PATH_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_05
{
    class Path
    {
    public:
        Path(SDL_Framework *framework)
        {
            radius_ = 20;
            start_ = Vector(0, framework->Height() / 3);
            end_ = Vector(framework->Width(), (2 * framework->Height()) / 3);
        }
        void Show(SDL_Framework *framework);
    private:
        int     radius_;
        Vector start_;
        Vector end_;
    };
}

#endif

