#ifndef EXAMPLE_07_03_SKETCH_H
#define EXAMPLE_07_03_SKETCH_H

#include "../Common/P5SDL.h"
#include "../Common/Utils.h"
#include "Example_07_03_Cell.h"

namespace nature_of_code_chapter_07_example_03
{
    class Sketch : public P5SDL
    {
    public:
        Sketch() : P5SDL("Example 7.3: Object-Oriented Game of Life", -1, -1, 640, 240, 0) {};
        bool Setup(void) override;
        bool Draw(void) override;
        void Cleanup(void) override;
        vector<vector<Cell *>> Create2DArray(int columns, int rows);
    private:
        int _w;
        int _columns;
        int _rows;
        vector<vector<Cell *>> _board;
    };
}

#endif
