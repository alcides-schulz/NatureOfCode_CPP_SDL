#ifndef EXAMPLE_05_07_PATH_H
#define EXAMPLE_05_07_PATH_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_07
{
    class Path
    {
    public:
        Path(void);
        void Show(SDL_Framework *framework);
        void AddPoint(int x, int y);
    private:
        int     radius_;
        vector <Vector> points_;
    };
}

#endif

