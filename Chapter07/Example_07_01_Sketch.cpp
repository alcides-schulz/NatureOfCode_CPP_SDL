#include "Example_07_01_Sketch.h"

namespace nature_of_code_chapter_07_example_01
{
    bool Sketch::Setup(void)
    {
        Background(255);
        _generation = 0;
        _w = 10;
        _rule_set.assign({ 0, 1, 0, 1, 1, 0, 1, 0 });
        _cells.resize((int)floor(Width() / _w));
        for (int i = 0; i < _cells.size(); i++)
            _cells[i] = 0;
        _cells[(int)floor(_cells.size() / 2)] = 1;
        return true;
    }

    bool Sketch::Draw(void)
    {
        for (int i = 1; i < _cells.size() - 1; i++) {
            if (_cells[i] == 1) {
                Fill(0);
                Rect(i * _w, _generation * _w, _w, _w);
            }
        }

        vector<int> next_gen = _cells;
        for (int i = 1; i < _cells.size() - 1; i++) {
            auto left = _cells[i - 1];
            auto me = _cells[i];
            auto right = _cells[i + 1];
            next_gen[i] = Rules(left, me, right);
        }
        _cells = next_gen;

        _generation++;

        if (_generation * _w > Height()) {
            NoLoop();
        }

        return true;
    }

    int Sketch::Rules(int a, int b, int c)
    {
        auto s = to_string(a) + to_string(b) + to_string(c);
        auto index = stoi(s, nullptr, 2);
        return _rule_set[7 - index];
    }
 }

// END
