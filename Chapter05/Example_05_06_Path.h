#ifndef EXAMPLE_05_06_PATH_H
#define EXAMPLE_05_06_PATH_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_06
{
    class Path
    {
    public:
        Path(SDL_Framework *framework);
        void Show(SDL_Framework *framework);
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

