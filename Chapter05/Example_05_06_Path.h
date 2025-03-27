#ifndef EXAMPLE_05_06_PATH_H
#define EXAMPLE_05_06_PATH_H

#include "../Common/SDL_Framework.h"
#include "../Common/PVector.h"

namespace nature_of_code_chapter_05_example_06
{
    class Path
    {
    public:
        Path(SDL_Framework *framework);
        void Show(SDL_Framework *framework);
        PVector GetStart(void) { return start_; };
        PVector GetEnd(void) { return end_; };
        int GetRadius(void) { return radius_; };
    private:
        int     radius_;
        PVector start_;
        PVector end_;
    };
}

#endif

