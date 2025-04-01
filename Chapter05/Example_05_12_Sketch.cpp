#include "Example_05_12_Sketch.h"

namespace nature_of_code_chapter_05_example_12
{
    vector<vector<vector<Boid *>>> gGrid;
    int gRows;
    int gCols;
    int gResolution = 40;

    bool Sketch::Setup(void)
    {
        gCols = (int)floor(Width() / gResolution);
        gRows = (int)floor(Height() / gResolution);
        gGrid = vector<vector<vector<Boid *>>>(gCols, vector<vector<Boid *>>(gRows));
        _flock = new Flock();
        for (int i = 0; i < 800; i++) {
            auto boid = new Boid(this, Width() / 2, Height() / 2);
            _flock->AddBoid(boid);
        }
        cout << "Drag mouse to add more boids." << endl;
        return true;
    }

    bool Sketch::Draw(void)
    {
        Background(255);
        for (int i = 0; i < gCols; i++) {
            for (int j = 0; j < gRows; j++) {
                gGrid[i][j].clear();
            }
        }

        for (auto boid : _flock->GetBoids()) {
            auto col = (int)floor(boid->GetPosition().x / gResolution);
            auto row = (int)floor(boid->GetPosition().y / gResolution);
            col = Utils::Constrain(col, 0, gCols - 1);
            row = Utils::Constrain(row, 0, gRows - 1);
            gGrid[col][row].push_back(boid);
        }

        Stroke(200);
        StrokeWeight(1);
        for (int i = 0; i <= gCols; i++) {
            auto x = i * gResolution;
            Line(x, 0, x, Height());
        }
        for (int j = 0; j <= gRows; j++) {
            auto y = j * gResolution;
            Line(0, y, Width(), y);
        }

        auto mouse_col = (int)floor(MousePosition().x / gResolution);
        auto mouse_row = (int)floor(MousePosition().y / gResolution);
        Stroke(0);
        StrokeWeight(2);
        Fill({ 255, 50, 50, 10 });
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                auto col = mouse_col + i;
                auto row = mouse_row + j;
                if (col >= 0 && col < gCols && row >= 0 && row < gRows) {
                    Rect(col * gResolution, row * gResolution, gResolution, gResolution);
                }
            }
        }

        _flock->Run();

        if (IsMouseButtonHeld(kMouseLeftButton))
            _flock->AddBoid(new Boid(this, MousePosition().x, MousePosition().y));

        return true;
    }

    void Sketch::Cleanup(void)
    {
        _flock->Cleanup();
        delete _flock;
    }
}

// END
