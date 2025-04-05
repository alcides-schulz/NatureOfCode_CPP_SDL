#include "Example_07_03_Sketch.h"

namespace nature_of_code_chapter_07_example_03
{
    bool Sketch::Setup(void)
    {
        _w = 8;
        _columns = Width() / _w;
        _rows = Height() / _w;
        _board = Create2DArray(_columns, _rows);
        for (int i = 0; i < _columns; i++) {
            for (int j = 0; j < _rows; j++) {
                auto state = (int)floor(Utils::Random(2.0f));
                if (i == 0 || j == 0 || i == _columns - 1 || j == _rows - 1)
                    state = 0;
                _board[i][j] = new Cell(this, state, i * _w, j * _w, _w);
            }
        }
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);

        for (int x = 1; x < _columns - 1; x++) {
            for (int y = 1; y < _rows - 1; y++) {
                auto neighbor_sum = 0;
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        neighbor_sum += _board[x + i][y + j]->GetPrevious();
                    }
                }
                neighbor_sum -= _board[x][y]->GetPrevious();

                if (_board[x][y]->GetState() == 1 && neighbor_sum < 2)
                    _board[x][y]->SetState(0);
                else if (_board[x][y]->GetState() == 1 && neighbor_sum > 3)
                    _board[x][y]->SetState(0);
                else if (_board[x][y]->GetState() == 0 && neighbor_sum == 3)
                    _board[x][y]->SetState(1);
            }
        }

        for (int i = 0; i < _columns; i++) {
            for (int j = 0; j < _rows; j++) {
                _board[i][j]->Show();
                _board[i][j]->SetPrevious(_board[i][j]->GetState());
            }
        }

        return true;
    }

    vector<vector<Cell *>> Sketch::Create2DArray(int columns, int rows)
    {
        return vector<vector<Cell *>>(columns, vector<Cell *>(rows));
    }

    void Sketch::Cleanup(void)
    {
        for (int i = 0; i < _columns; i++) {
            for (int j = 0; j < _rows; j++) {
                delete _board[i][j];
            }
        }
    }
}

// END
