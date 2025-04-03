#include "Example_07_02_Sketch.h"

namespace nature_of_code_chapter_07_example_02
{
    bool Sketch::Setup(void)
    {
        _w = 8;
        _columns = Width() / _w;
        _rows = Height() / _w;
        _board = Create2DArray(_columns, _rows);
        for (int i = 1; i < _columns - 1; i++) {
            for (int j = 1; j < _rows - 1; j++) {
                _board[i][j] = (int)floor(Utils::Random(2.0f));
            }
        }
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        auto next = Create2DArray(_columns, _rows);

        for (int i = 1; i < _columns - 1; i++) {
            for (int j = 1; j < _rows - 1; j++) {
                auto neighbor_sum = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        neighbor_sum += _board[i + k][j + l];
                    }
                }
                neighbor_sum -= _board[i][j];
                if (_board[i][j] == 1 && neighbor_sum < 2)       next[i][j] = 0;
                else if (_board[i][j] == 1 && neighbor_sum > 3)  next[i][j] = 0;
                else if (_board[i][j] == 0 && neighbor_sum == 3) next[i][j] = 1;
                else next[i][j] = _board[i][j];
            }
        }

        Stroke(0);
        StrokeWeight(1);
        for (int i = 1; i < _columns - 1; i++) {
            for (int j = 1; j < _rows - 1; j++) {
                Fill(255 - _board[i][j] * 255);
                Rect(i * _w, j * _w, _w, _w);
            }
        }

        _board = next;

        return true;
    }

    vector<vector<int>> Sketch::Create2DArray(int columns, int rows)
    {
        return vector<vector<int>>(columns, vector<int>(rows, 0));
    }
}

// END
