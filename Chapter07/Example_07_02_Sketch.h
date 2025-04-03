#ifndef EXAMPLE_07_02_SKETCH_H
#define EXAMPLE_07_02_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common//Utils.h"

namespace nature_of_code_chapter_07_example_02
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 7.2: Game of Life", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        vector<vector<int>> Create2DArray(int columns, int rows);
    private:
        int _w;
        int _columns;
        int _rows;
        vector<vector<int>> _board;
    };
}

#endif
