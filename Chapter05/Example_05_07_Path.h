#ifndef EXAMPLE_05_07_PATH_H
#define EXAMPLE_05_07_PATH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_07
{
    class Path
    {
    public:
        Path(void);
        void Show(P5SDL *p5sdl);
        void AddPoint(int x, int y);
    private:
        int             _radius;
        vector <Vector> _points;
    };
}

#endif

