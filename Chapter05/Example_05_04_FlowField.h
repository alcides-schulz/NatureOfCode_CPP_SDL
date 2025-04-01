#ifndef EXAMPLE_05_04_FLOWFIELD_H
#define EXAMPLE_05_04_FLOWFIELD_H

#include "../Common/P5SDL.h"
#include "../Common/Vector.h"
#include "../Common/Utils.h"
#include "../Common/PerlinNoise2D.h"

namespace nature_of_code_chapter_05_example_04
{
    class FlowField
    {
    public:
        FlowField(int width, int height, int resolution)
        {
            _resolution = resolution;
            _cols = width / _resolution;
            _rows = height / _resolution;
            _field = vector<vector<Vector>>(_cols, vector<Vector>(_rows));
            Init();
        };
        void Init(void);
        void Show(P5SDL *p5sdl);
        Vector Lookup(Vector position);
    private:
        int     _resolution;
        int     _rows;
        int     _cols;
        vector<vector<Vector>> _field;
    };
}

#endif
