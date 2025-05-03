#include "Example_09_05_Food.h"

namespace nature_of_code_chapter_09_example_05
{
    Food::Food(P5SDL *p5sdl, int num)
    {
        _p5sdl = p5sdl;
        for (int i = 0; i < num; i++) {
            auto x = Utils::Random(_p5sdl->Width());
            auto y = Utils::Random(_p5sdl->Height());
            _food_positions.push_back(Vector(x, y));
        }
    }

    void Food::Add(Vector position)
    {
        _food_positions.push_back(position.Copy());
    }

    void Food::Run(void)
    {
        for (auto position : _food_positions) {
            _p5sdl->RectMode(kRectCenter);
            _p5sdl->Stroke(0);
            _p5sdl->StrokeWeight(1);
            _p5sdl->Fill(200);
            _p5sdl->Square((int)position.x, (int)position.y, 8);
        }
        if (Utils::Random(1.0f) < 0.001f) {
            auto x = Utils::Random(_p5sdl->Width());
            auto y = Utils::Random(_p5sdl->Height());
            _food_positions.push_back(Vector(x, y));
        }
    }
}

// END
