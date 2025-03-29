#ifndef EXAMPLE_05_08_PATH_H
#define EXAMPLE_05_08_PATH_H

#include "../Common/SDL_Framework.h"
#include "../Common/Vector.h"

namespace nature_of_code_chapter_05_example_08
{
    class Path
    {
    public:
        Path(void);
        void Show(SDL_Framework *framework);
        void AddPoint(float x, float y);
        vector<Vector> GetPoints(void) { return points_; };
        int GetRadius(void) { return radius_; };
        Vector GetStart(void) { return points_[0]; };
        Vector GetEnd(void) { return points_[points_.size() - 1]; };
    private:
        int     radius_;
        vector <Vector> points_;
    };
}

#endif

