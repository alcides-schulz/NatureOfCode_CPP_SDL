#ifndef EXAMPLE_05_08_PATH_H
#define EXAMPLE_05_08_PATH_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_08
{
    class Path
    {
    public:
        Path(void);
        void Show(P5SDL *p5sdl);
        void AddPoint(float x, float y);
        vector<Vector> GetPoints(void) { return _points; };
        int GetRadius(void) { return _radius; };
        Vector GetStart(void) { return _points[0]; };
        Vector GetEnd(void) { return _points[_points.size() - 1]; };
    private:
        int             _radius;
        vector <Vector> _points;
    };
}

#endif

